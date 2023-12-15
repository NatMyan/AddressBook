#ifndef ADDRESS_BOOK_INTERFACE_HPP
#define ADDRESS_BOOK_INTERFACE_HPP

#include "../Logic/AddressBookLogic.hpp"
#include "TabNames.hpp"

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTabWidget>

class AddressBookInterface : public QWidget {
    Q_OBJECT

    public:
        AddressBookInterface(AddressBookLogic* logic, QWidget* parent = nullptr);

    private slots:
        void onAddContactClicked();
        void onSearchClicked(const QString& searchOption, const QString& searchName);
        void onTabChanged(int index);

    private:
        void setupUi();
        void updateTabNames();
        void updateContactTable(const QList<Contact>& contacts);

    private:
        AddressBookLogic* logic_;
        QTableWidget* contactTable_;
        QTabWidget* tabWidget_;
        QLineEdit* searchNameLineEdit_;
        QComboBox* searchOptionComboBox_;
        TabNames tabNames_;
};

#endif // ADDRESS_BOOK_INTERFACE_HPP


/*#ifndef ADDRESS_BOOK_INTERFACE_HPP
#define ADDRESS_BOOK_INTERFACE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QTabWidget>
#include "AddDialog.hpp"
#include "SearchDialog.hpp"
#include "SearchResultDialog.hpp"
#include "Database.hpp"

class AddressBookInterface : public QWidget {
    Q_OBJECT

public:
    AddressBookInterface(const QString& username, QWidget* parent = nullptr);

private slots:
    void onAddButtonClicked();
    void onSearchButtonClicked();
    void onContactAdded(const QString& name, const QString& phone, const QString& email, const QString& tab);

private:
    void setupUi();
    void updateTable();
    void createTabs();
    void performSearch(const QString& searchName, const QString& searchOption);

private:
    QString username_;
    QTableWidget* contactTable_;
    QPushButton* addButton_;
    QPushButton* searchButton_;
    QTabWidget* tabWidget_;
    Database database_;
};

#endif // ADDRESS_BOOK_INTERFACE_HPP*/