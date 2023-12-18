#ifndef TABLE_INTERFACE_HPP
#define TABLE_INTERFACE_HPP

#include "../Data/DatabaseManager.hpp"
#include "../Data/TabNames.hpp"
#include "../Data/AddressBookModel.hpp"

#include <QWidget>
#include <QTabWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlTableModel>

class TableInterface : public QWidget {
    Q_OBJECT

    public:
        TableInterface(QWidget *parent = nullptr);

    public slots:
        void onShowDatabaseContents(const QSqlDatabase& db);
        void onAddTabClicked();
        void onAddContactClicked();
        void onSignOutClicked();
        void onSearchContacts();
    
    signals:
        void sigAddContactClicked();
        void sigSearchClicked();
        void sigSignOutClicked();
    
    private:    
        void setupUi();

    private:
        QTabWidget *tabWidget_;
        QPushButton *addTabButton_;
        QPushButton *addContactButton_;
        QPushButton *searchButton_;
        QPushButton *signOutButton_;
        QTableWidget *currentTable_;
        QVector<QTableWidget*> currTables_;
        TabNames tabNames_; 
        AddressBookModel* model_;
};

#endif // TABLE_INTERFACE_HPP