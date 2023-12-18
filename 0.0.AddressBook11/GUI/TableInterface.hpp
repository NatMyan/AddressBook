#ifndef ADDRESS_BOOK_INTERFACE_HPP
#define ADDRESS_BOOK_INTERFACE_HPP

#include "../Logic/TableLogic.hpp"
#include "../Data/TabNames.hpp"

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlTableModel>

class TableInterface : public QWidget {
    Q_OBJECT

    public:
        TableInterface(TableLogic* logic, QWidget* parent = nullptr);

    public:
        QTableWidget* getCurrentTable() const;

    signals:
        void sigTabAdded(const QString& tabName);
        void sigSignOutClicked();

    public slots:
        void onAddTabClicked();
        void onAddContactClicked();
        void onSignOutClicked();
        void onEditContact(QTableWidgetItem* item);
        void onSearchContacts();
        void onShowDatabaseContents();
        
    private:
        void setupUi();
        void setupTabs();
        QTableWidget* createEditableTable();

    private:
        QTabWidget* tabWidget_;
        QPushButton* addTabButton_;
        QPushButton* addContactButton_;
        QPushButton* searchButton_;
        QPushButton* signOutButton_;
        QTableWidget* currentTable_;
        QVector<QTableWidget*> currTables_;
        TabNames tabNames_; 
        TableLogic* logic_;
};

#endif // ADDRESS_BOOK_INTERFACE_HPP

