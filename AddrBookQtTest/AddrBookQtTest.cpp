#include <QString>
#include <QDataStream>
#include <QAbstractTableModel>
#include <QItemSelection>
#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include <QButtonGroup>
#include <QStandardPaths>
#include <QRegularExpression>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QMessageBox>
#include <QIODevice>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QMenuBar>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>

//---------------------------------------------------------------------------------------------
struct Contact
{
    QString name;
    QString address;
    
    bool operator==(const Contact &other) const
    {
        return name == other.name && address == other.address;
    }
};

//---------------------------------------------------------------------------------------------
inline QDataStream &operator<<(QDataStream &stream, const Contact &contact)
{
    return stream << contact.name << contact.address;
}

inline QDataStream &operator>>(QDataStream &stream, Contact &contact)
{
    return stream >> contact.name >> contact.address;
}

//---------------------------------------------------------------------------------------------
class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = nullptr);
    TableModel(const QList<Contact> &contacts, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    const QList<Contact> &getContacts() const;

private:
    bool readData();
    bool writeData();
    QList<Contact> contacts;
};

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    readData();
}

TableModel::TableModel(const QList<Contact> &contacts, QObject *parent)
    : QAbstractTableModel(parent), contacts(contacts)
{
    readData();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : contacts.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= contacts.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &contact = contacts.at(index.row());

        switch (index.column()) {
            case 0:
                return contact.name;
            case 1:
                return contact.address;
            default:
                break;
        }
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
            case 1:
                return tr("Address");
            default:
                break;
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        contacts.insert(position, { QString(), QString() });

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        contacts.removeAt(position);

    endRemoveRows();
    return true;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto contact = contacts.value(row);

        switch (index.column()) {
            case 0:
                contact.name = value.toString();
                break;
            case 1:
                contact.address = value.toString();
                break;
            default:
                return false;
        }
        contacts.replace(row, contact);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

const QList<Contact> &TableModel::getContacts() const
{
    return contacts;
}

bool TableModel::readData() 
{
    QSqlQuery query;
    if (query.exec("SELECT id, name, address FROM contacts")) {
        // Clear existing data
        contacts.clear();

        while (query.next()) {
            Contact contact;
            // contact.id = query.value(0).toInt();
            contact.name = query.value(1).toString();
            contact.address = query.value(2).toString();
            contacts.append(contact);
        }

        // Inform views that the data has changed
        // reset();
        return true;
    }

    qDebug() << "Error reading data:" << query.lastError().text();
    return false;
}

bool TableModel::writeData() 
{
    QSqlQuery query;
    if (query.exec("DELETE FROM contacts")) {
        for (const auto &contact : contacts) {
            query.prepare("INSERT INTO contacts (name, address) VALUES (?, ?)");
            query.addBindValue(contact.name);
            query.addBindValue(contact.address);

            if (!query.exec()) {
                qDebug() << "Error writing data:" << query.lastError().text();
                return false;
            }
        }
        return true;
    }

    qDebug() << "Error clearing data:" << query.lastError().text();
    return false;
}


//---------------------------------------------------------------------------------------------
class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = nullptr);

    QString name() const;
    QString address() const;
    void editAddress(const QString &name, const QString &address);

private:
    QLineEdit *nameText;
    QTextEdit *addressText;
};

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent),
      nameText(new QLineEdit),
      addressText(new QTextEdit)
{
    auto nameLabel = new QLabel(tr("Name"));
    auto addressLabel = new QLabel(tr("Address"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(addressLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(addressText, 1, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Contact"));
}

QString AddDialog::name() const
{
    return nameText->text();
}

QString AddDialog::address() const
{
    return addressText->toPlainText();
}

void AddDialog::editAddress(const QString &name, const QString &address)
{
    nameText->setReadOnly(true);
    nameText->setText(name);
    addressText->setPlainText(address);
}

//---------------------------------------------------------------------------------------------
class NewAddressTab : public QWidget
{
    Q_OBJECT

public:
    NewAddressTab(QWidget *parent = nullptr);

public slots:
    void addEntry();

signals:
    void sendDetails(const QString &name, const QString &address);
};

NewAddressTab::NewAddressTab(QWidget *parent)
    : QWidget(parent)
{
    auto descriptionLabel = new QLabel(tr("There are currently no contacts in your address book. "
                                          "\nClick Add to add new contacts."));

    auto addButton = new QPushButton(tr("Add"));

    connect(addButton, &QAbstractButton::clicked, this, &NewAddressTab::addEntry);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}

void NewAddressTab::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec())
        emit sendDetails(aDialog.name(), aDialog.address());
}

//---------------------------------------------------------------------------------------------
class AddressWidget : public QTabWidget
{
    Q_OBJECT

public:
    AddressWidget(QWidget *parent = nullptr);
    // void readFromFile();
    // void writeToFile();

    void readFromDatabase();
    void writeToDatabase();

public slots:
    void showAddEntryDialog();
    void addEntry(const QString &name, const QString &address);
    void editEntry();
    void removeEntry();
    void addNewEntry();

signals:
    void selectionChanged (const QItemSelection &selected);

private:
    void setupTabs();

    inline static QString fileName =
        QStandardPaths::standardLocations(QStandardPaths::TempLocation).value(0)
        + QStringLiteral("/addressbook.dat");
    TableModel *table;
    NewAddressTab *newAddressTab;
    QPushButton *addButton;
};

AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent),
      table(new TableModel(this)),
      newAddressTab(new NewAddressTab(this)),
      addButton(new QPushButton(tr("+"), this)) // Initialize the QPushButton
{
    connect(newAddressTab, &NewAddressTab::sendDetails,
            this, &AddressWidget::addEntry);

    connect(addButton, &QPushButton::clicked,
            this, &AddressWidget::addNewEntry); // Connect the button's clicked signal to the slot

    addTab(newAddressTab, tr("Address Book"));

    setupTabs();

    // Add the QPushButton to the layout
    auto layout = new QVBoxLayout;
    layout->addWidget(addButton, 0, Qt::AlignTop | Qt::AlignLeft);
    setLayout(layout);
}

void AddressWidget::addNewEntry()
{
    showAddEntryDialog();
}

void AddressWidget::setupTabs()
{
    using namespace Qt::StringLiterals;
    const auto groups = { "ABC"_L1, "DEF"_L1, "GHI"_L1, "JKL"_L1, "MNO"_L1, "PQR"_L1,
                          "STU"_L1, "VW"_L1, "XYZ"_L1 };

    for (QLatin1StringView str : groups) {
        const auto regExp = QRegularExpression(QLatin1StringView("^[%1].*").arg(str),
                                               QRegularExpression::CaseInsensitiveOption);

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

        connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
                this, &AddressWidget::selectionChanged);

        connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
            if (widget(tabIndex) == tableView)
                emit selectionChanged(tableView->selectionModel()->selection());
        });

        addTab(tableView, str);
    }
}

void AddressWidget::showAddEntryDialog()
{
    AddDialog aDialog;

    if (aDialog.exec())
        addEntry(aDialog.name(), aDialog.address());
}

void AddressWidget::addEntry(const QString &name, const QString &address)
{
    if (!table->getContacts().contains({ name, address })) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);
        index = table->index(0, 1, QModelIndex());
        table->setData(index, address, Qt::EditRole);
        removeTab(indexOf(newAddressTab));
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The name \"%1\" already exists.").arg(name));
    }
}

void AddressWidget::editEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();
    QString name;
    QString address;
    int row = -1;

    for (const QModelIndex &index : indexes) {
        row = proxy->mapToSource(index).row();
        QModelIndex nameIndex = table->index(row, 0, QModelIndex());
        QVariant varName = table->data(nameIndex, Qt::DisplayRole);
        name = varName.toString();

        QModelIndex addressIndex = table->index(row, 1, QModelIndex());
        QVariant varAddr = table->data(addressIndex, Qt::DisplayRole);
        address = varAddr.toString();
    }
    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Contact"));
    aDialog.editAddress(name, address);

    if (aDialog.exec()) {
        const QString newAddress = aDialog.address();
        if (newAddress != address) {
            const QModelIndex index = table->index(row, 1, QModelIndex());
            table->setData(index, newAddress, Qt::EditRole);
        }
    }
}

void AddressWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    const QModelIndexList indexes = selectionModel->selectedRows();

    for (QModelIndex index : indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
    }

    if (table->rowCount(QModelIndex()) == 0)
        insertTab(0, newAddressTab, tr("Address Book"));
}

/*void AddressWidget::writeToFile()
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out << table->getContacts();
}

void AddressWidget::readFromFile()
{
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

void AddressWidget::readFromDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("addressbook.db"); // SQLite database file name

    if (!db.open()) {
        QMessageBox::information(this, tr("Database Error"),
                                 db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, address TEXT)");

    if (!query.exec("SELECT name, address FROM contacts")) {
        QMessageBox::information(this, tr("Query Error"),
                                 query.lastError().text());
        return;
    }

    while (query.next()) {
        QString name = query.value(0).toString();
        QString address = query.value(1).toString();
        addEntry(name, address);
    }
}

void AddressWidget::writeToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("addressbook.db"); // SQLite database file name

    if (!db.open()) {
        QMessageBox::information(this, tr("Database Error"), db.lastError().text());
        // qDebug() << "Error opening database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts (name TEXT, address TEXT)");
    query.exec("DELETE FROM contacts"); // Clear existing data

    for (const auto &contact : table->getContacts()) {
        query.prepare("INSERT INTO contacts (name, address) VALUES (?, ?)");
        query.addBindValue(contact.name);
        query.addBindValue(contact.address);

        if (!query.exec()) {
            QMessageBox::information(this, tr("Query Error"),
                                     query.lastError().text());
            return;
        }
    }
}

//---------------------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void updateActions(const QItemSelection &selection);
    void openFile();
    void saveFile();

private:
    void createMenus();

    AddressWidget *addressWidget;
    QAction *editAct;
    QAction *removeAct;
    QAction *saveAct; // New save action
};

MainWindow::MainWindow()
    : QMainWindow(),
      addressWidget(new AddressWidget)
{
    setCentralWidget(addressWidget);
    createMenus();
    setWindowTitle(tr("Address Book"));
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAct = new QAction(tr("&Open..."), this);
    fileMenu->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

    saveAct = new QAction(tr("&Save"), this); // New save action
    fileMenu->addAction(saveAct);
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);

    QMenu *toolMenu = menuBar()->addMenu(tr("&Tool"));
    editAct = new QAction(tr("&Edit Entry..."), this);
    editAct->setEnabled(false);
    toolMenu->addAction(editAct);
    connect(editAct, &QAction::triggered, addressWidget, &AddressWidget::editEntry);

    toolMenu->addSeparator();

    removeAct = new QAction(tr("&Remove Entry"), this);
    removeAct->setEnabled(false);
    toolMenu->addAction(removeAct);
    connect(removeAct, &QAction::triggered, addressWidget, &AddressWidget::removeEntry);

    connect(addressWidget, &AddressWidget::selectionChanged,
        this, &MainWindow::updateActions);
}

void MainWindow::openFile()
{
    addressWidget->readFromDatabase();
}

void MainWindow::saveFile()
{
    addressWidget->writeToDatabase();
}

void MainWindow::updateActions(const QItemSelection &selection)
{
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty()) {
        removeAct->setEnabled(true);
        editAct->setEnabled(true);
    } 
    else {
        removeAct->setEnabled(false);
        editAct->setEnabled(false);
    }
}

//---------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}

#include "AddrBookQtTest.moc"

