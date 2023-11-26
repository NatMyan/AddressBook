// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QTableView>
#include <QApplication>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onAddButtonClicked();
    void onOpenButtonClicked();
    void onSearchButtonClicked();

private:
    void setupUi();
    void setupDatabase();
    void setupTable();
    void openDatabase(const QString &path);
    void searchContacts(const QString &name, const QString &phone, const QString &email);

    QSqlDatabase database;
    QTableView *tableView;
    QStandardItemModel *model;
};

// #endif // MAINWINDOW_H

// #include "MainWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>

// #include "MainWindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
    setupDatabase();
    setupTable();
}

void MainWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *addButton = new QPushButton("Add", this);
    QPushButton *openButton = new QPushButton("Open", this);
    QPushButton *searchButton = new QPushButton("Search", this);

    tableView = new QTableView(this);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(openButton, &QPushButton::clicked, this, &MainWindow::onOpenButtonClicked);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);

    layout->addWidget(addButton);
    layout->addWidget(openButton);
    layout->addWidget(searchButton);
    layout->addWidget(tableView);
}

void MainWindow::setupDatabase() {
    // Setup your database connection here
    // For simplicity, we'll use an in-memory database
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(":memory:");

    if (!database.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database");
        QApplication::exit();
    }
}

void MainWindow::setupTable() {
    model = new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels({"Name", "Phone", "Email"});
    tableView->setModel(model);
}

void MainWindow::onAddButtonClicked() {
    // Open dialog to get input for new contact
    QString name = QInputDialog::getText(this, "Add Contact", "Name:");
    QString phone = QInputDialog::getText(this, "Add Contact", "Phone:");
    QString email = QInputDialog::getText(this, "Add Contact", "Email:");

    if (!name.isEmpty() && !phone.isEmpty() && !email.isEmpty()) {
        QSqlQuery query(database);
        query.prepare("INSERT INTO contacts (name, phone, email) VALUES (:name, :phone, :email)");
        query.bindValue(":name", name);
        query.bindValue(":phone", phone);
        query.bindValue(":email", email);

        if (query.exec()) {
            QMessageBox::information(this, "Success", "Contact added successfully");
            // Refresh the table
            searchContacts("", "", "");
        } else {
            QMessageBox::critical(this, "Error", "Failed to add contact: " + query.lastError().text());
        }
    }
}

void MainWindow::onOpenButtonClicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open Database", "", "SQLite Database (*.db *.sqlite)");
    if (!filePath.isEmpty()) {
        openDatabase(filePath);
    }
}

void MainWindow::onSearchButtonClicked() {
    // Open dialog to get search criteria
    QString name = QInputDialog::getText(this, "Search Contacts", "Name:");
    QString phone = QInputDialog::getText(this, "Search Contacts", "Phone:");
    QString email = QInputDialog::getText(this, "Search Contacts", "Email:");

    // Perform the search
    searchContacts(name, phone, email);
}

void MainWindow::openDatabase(const QString &path) {
    // Open an existing database
    database.close();
    database.setDatabaseName(path);

    if (!database.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database");
        return;
    }

    // Load data into the table
    searchContacts("", "", "");
}

void MainWindow::searchContacts(const QString &name, const QString &phone, const QString &email) {
    model->removeRows(0, model->rowCount());

    QSqlQuery query(database);
    query.prepare("SELECT * FROM contacts WHERE name LIKE :name AND phone LIKE :phone AND email LIKE :email");
    query.bindValue(":name", "%" + name + "%");
    query.bindValue(":phone", "%" + phone + "%");
    query.bindValue(":email", "%" + email + "%");

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            model->insertRow(row);
            model->setData(model->index(row, 0), query.value("name").toString());
            model->setData(model->index(row, 1), query.value("phone").toString());
            model->setData(model->index(row, 2), query.value("email").toString());
            ++row;
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to search contacts: " + query.lastError().text());
    }
}


// #include "MainWindow.h"
// #include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "testAddrBook.moc"