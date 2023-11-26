#ifndef ADDRESS_BOOK_LOGIC_HPP
#define ADDRESS_BOOK_LOGIC_HPP

#include "../GUI/AddDialog.hpp"
#include "../GUI/OpenDialog.hpp"
#include "../GUI/SearchDialog.hpp"
#include "../GUI/SaveDialog.hpp"

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>

class AddressBookLogic : public QObject {
    Q_OBJECT

    public:
        explicit AddressBookLogic(QObject *parent = nullptr);

    public slots:
        void addContact();
        void editContact(QTableWidgetItem *item);
        void openAddressBook();
        void searchContacts();
        void saveAddressBook();

    signals:
        void contactAdded(const QString &name, const QString &phone, const QString &email);
        void contactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email);

    private slots:
        void handleAddContactRequest();

    private:
        AddDialog *addDialog; 
        OpenDialog *openDialog;
        SearchDialog *searchDialog;
        SaveDialog *saveDialog;
};

#endif // ADDRESS_BOOK_LOGIC_HPP


/*
// AddressBookLogic.hpp
#ifndef ADDRESS_BOOK_LOGIC_HPP
#define ADDRESS_BOOK_LOGIC_HPP

#include "../GUI/AddDialog.hpp"
#include "../GUI/OpenDialog.hpp"
#include "../GUI/SearchDialog.hpp"
#include "../GUI/SaveDialog.hpp"

#include <QObject>
#include <QTableWidget>
#include <QTableWidgetItem>

class AddressBookLogic : public QObject {
    Q_OBJECT

public:
    explicit AddressBookLogic(QObject *parent = nullptr);

public slots:
    void addContact();
    void editContact(QTableWidgetItem *item);
    void openAddressBook();
    void searchContacts();
    void saveAddressBook();

signals:
    void contactAdded(const QString &name, const QString &phone, const QString &email);
    void contactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email);

private slots:
    void handleAddContactRequest();

private:
    AddDialog *addDialog;
    OpenDialog *openDialog;
    SearchDialog *searchDialog;
    SaveDialog *saveDialog;
};

#endif // ADDRESS_BOOK_LOGIC_HPP
*/