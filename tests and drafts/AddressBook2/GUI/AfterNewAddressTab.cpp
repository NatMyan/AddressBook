#include "AfterNewAddressTab.hpp"
#include "AddDialog.hpp"
#include "OpenDialog.hpp"

#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QHeaderView>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlError>

AfterNewAddressTab::AfterNewAddressTab(QWidget *parent) : 
    // QWidget(parent),
    QTabWidget(parent),
    table(new TableModel(this)),
    dbManager(new DatabaseManager()),
    // newAddressTab(new NewAddressTab(this)),
    addButton(new QPushButton(tr("Add"), this)),
    openButton(new QPushButton(tr("Open"), this))
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("address_book.db");

    // connect(newAddressTab, &NewAddressTab::sendDetails, this, &AfterNewAddressTab::addEntry);
    // connect(newAddressTab, &NewAddressTab::sendFilePath, this, &AfterNewAddressTab::openEntry);

    connect(addButton, &QPushButton::clicked, this, &AfterNewAddressTab::addNewEntry); 
    connect(openButton, &QPushButton::clicked, this, &AfterNewAddressTab::openNewEntry);

    // addTab(newAddressTab, tr("Address Book"));

    setupTabs();

    auto layout = new QHBoxLayout;
    layout->addWidget(addButton, 0, Qt::AlignTop | Qt::AlignLeft);
    layout->addWidget(openButton, 0, Qt::AlignTop | Qt::AlignLeft);
    setLayout(layout);
}

void AfterNewAddressTab::setupTabs() {
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

        connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &AfterNewAddressTab::selectionChanged);

        connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
            if (widget(tabIndex) == tableView)
                emit selectionChanged(tableView->selectionModel()->selection());
        });

        addTab(tableView, str);
    }
}


void AfterNewAddressTab::addNewEntry() {
    showAddEntryDialog();
}

void AfterNewAddressTab::openNewEntry() {
    showOpenEntryDialog();
}

void AfterNewAddressTab::showAddEntryDialog() {
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.name(), aDialog.phone(), aDialog.email());
}

void AfterNewAddressTab::showOpenEntryDialog() {
    OpenDialog oDialog;

    if (oDialog.exec())
        openEntry(oDialog.getSelectedFilePath());
}

void AfterNewAddressTab::readFromDatabase() {
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
 
void AfterNewAddressTab::writeToDatabase() {
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

/*void AfterNewAddressTab::addEntry() {
    AddDialog aDialog;
    if (aDialog.exec())
        emit sendDetails(aDialog.name(), aDialog.phone(), aDialog.email());
}

void AfterNewAddressTab::openEntry() {
    OpenDialog oDialog;
    if (oDialog.exec()) 
        emit sendFilePath(oDialog.getSelectedFilePath());
}*/