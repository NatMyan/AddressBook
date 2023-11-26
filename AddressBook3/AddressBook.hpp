// AddressBook.hpp
#ifndef ADDRESSBOOK_HPP
#define ADDRESSBOOK_HPP

#include <QMainWindow>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QTableView>
#include <QApplication>
#include "AddressBookTab.hpp"

class AddressBook : public QMainWindow {
    Q_OBJECT

public:
    AddressBook(QWidget *parent = nullptr);

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
    AddressBookTab *addressBookTab;
};

#endif // ADDRESSBOOK_HPP
