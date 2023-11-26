#include "AddressWidget.hpp"
#include "AddDialog.hpp"
#include "OpenDialog.hpp"

#include <QVBoxLayout>
#include <QRegularExpression>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QHeaderView>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlError>

AddressWidget::AddressWidget(QWidget *parent) : 
    QTabWidget(parent),
    table(new TableModel(this)),
    dbManager(new DatabaseManager()),
    newAddressTab(new NewAddressTab(this)),
    addButton(new QPushButton(tr("Add"), this)),
    openButton(new QPushButton(tr("Open"), this))
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("address_book.db");

    connect(newAddressTab, &NewAddressTab::sendDetails, this, &AddressWidget::addEntry);
    connect(newAddressTab, &NewAddressTab::sendFilePath, this, &AddressWidget::openEntry);

    connect(addButton, &QPushButton::clicked, this, &AddressWidget::addNewEntry); 
    connect(openButton, &QPushButton::clicked, this, &AddressWidget::openNewEntry);

    addTab(newAddressTab, tr("Address Book"));

    setupTabs();

    auto layout = new QHBoxLayout;
    layout->addWidget(addButton, 0, Qt::AlignTop | Qt::AlignLeft);
    layout->addWidget(openButton, 0, Qt::AlignTop | Qt::AlignLeft);
    setLayout(layout);
}

void AddressWidget::addNewEntry() {
    showAddEntryDialog();
}

void AddressWidget::openNewEntry() {
    showOpenEntryDialog();
}

void AddressWidget::setupTabs() {
    using namespace Qt::StringLiterals;
    const auto groups = { "ABC"_L1, "DEF"_L1, "GHI"_L1, "JKL"_L1, "MNO"_L1, "PQR"_L1,
                          "STU"_L1, "VW"_L1, "XYZ"_L1 };

    for (QLatin1StringView str : groups) {
        const auto regExp = QRegularExpression(QLatin1StringView("^[%1].*").arg(str), QRegularExpression::CaseInsensitiveOption);

        auto proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(table);
        proxyModel->setFilterRegularExpression(regExp);
        proxyModel->setFilterKeyColumn(0);

        QTableView *tableView = new QTableView;
        tableView->setModel(proxyModel);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->hide();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSortingEnabled(true);

        connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &AddressWidget::selectionChanged);

        connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
            if (widget(tabIndex) == tableView)
                emit selectionChanged(tableView->selectionModel()->selection());
        });

        addTab(tableView, str);
    }
}

void AddressWidget::showAddEntryDialog() {
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.name(), aDialog.phone(), aDialog.email());
}

void AddressWidget::showOpenEntryDialog() {
    OpenDialog oDialog;

    if (oDialog.exec())
        openEntry(oDialog.getSelectedFilePath());
}

void AddressWidget::addEntry(const QString &name, const QString &phone, const QString &email) {
    if (!table->getContacts().contains({ name, phone, email })) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);

        index = table->index(0, 1, QModelIndex());
        table->setData(index, phone, Qt::EditRole);

        index = table->index(0, 2, QModelIndex());
        table->setData(index, email, Qt::EditRole);

        removeTab(indexOf(newAddressTab));
    } 
    else {
        QMessageBox::information(this, tr("Duplicate Name"), tr("The name \"%1\" already exists.").arg(name));
    }
}

void AddressWidget::openEntry(const QString &filePath) {
    if (dbManager->openDatabase(filePath)) {
        readFromDatabase();
    } 
    else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open the database."));
    }
}

void AddressWidget::editEntry() {
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();
    QString name;
    QString phone;
    QString email;
    int row = -1;

    for (const QModelIndex &index : indexes) {
        row = proxy->mapToSource(index).row();
        QModelIndex nameIndex = table->index(row, 0, QModelIndex());
        QVariant varName = table->data(nameIndex, Qt::DisplayRole);
        name = varName.toString();

        QModelIndex phoneIndex = table->index(row, 1, QModelIndex());
        QVariant varPh = table->data(phoneIndex, Qt::DisplayRole);
        phone = varPh.toString();

        QModelIndex emailIndex = table->index(row, 2, QModelIndex());
        QVariant varEml = table->data(emailIndex, Qt::DisplayRole);
        email = varEml.toString();
    }
    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Contact"));
    aDialog.editAddress(name, phone, email);

    if (aDialog.exec()) {
        const QString newEmail = aDialog.email();
        if (newEmail != email) {
            const QModelIndex index = table->index(row, 1, QModelIndex());
            table->setData(index, newEmail, Qt::EditRole);
        }
        const QString newPhone = aDialog.phone();
        if (newPhone != phone) {
            const QModelIndex index = table->index(row, 2, QModelIndex());
            table->setData(index, newPhone, Qt::EditRole);
        }
    }
}

void AddressWidget::removeEntry() {
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();

    for (QModelIndex index : indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
        table->removeRows(row, 2, QModelIndex());
    }

    if (table->rowCount(QModelIndex()) == 0)
        insertTab(0, newAddressTab, tr("Address Book"));
}

void AddressWidget::readFromDatabase() {
    if (!db.open()) {
        QMessageBox::information(this, tr("Database Error"), db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT, email TEXT)");

    if (!query.exec("SELECT name, phone, email FROM contacts")) {
        QMessageBox::information(this, tr("Query Error"), query.lastError().text());
        return;
    }

    while (query.next()) {
        QString name = query.value(0).toString();
        QString phone = query.value(1).toString();
        QString email = query.value(2).toString();
        addEntry(name, phone, email);
    }
}
 
void AddressWidget::writeToDatabase() {
    if (!db.open()) {
        QMessageBox::information(this, tr("Database Error"), db.lastError().text());
        qDebug() << "Database connection error:" << QSqlDatabase::database().lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, phone TEXT, email TEXT)");
    query.exec("DELETE FROM contacts"); 

    for (const auto &contact : table->getContacts()) {
        query.prepare("INSERT INTO contacts (name, phone, email) VALUES (?, ?)");
        query.addBindValue(contact.name);
        query.addBindValue(contact.phone);
        query.addBindValue(contact.email);

        if (!query.exec()) {
            QMessageBox::information(this, tr("Query Error"), query.lastError().text());
            return;
        }
    }
}

/*void AddressWidget::writeToFile() {
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out << table->getContacts();
}

void AddressWidget::readFromFile() {
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QList<Contact> contacts;
    QDataStream in(&file);
    in >> contacts;

    if (contacts.isEmpty()) {
        QMessageBox::information(this, tr("No contacts in file"),
                                 tr("The file you are attempting to open contains no contacts."));
    } else {
        for (const auto &contact: std::as_const(contacts))
            addEntry(contact.name, contact.address);
    }
}*/