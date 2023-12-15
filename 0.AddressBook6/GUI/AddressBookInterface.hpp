#ifndef ADDRESS_BOOK_INTERFACE_HPP
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

#endif // ADDRESS_BOOK_INTERFACE_HPP