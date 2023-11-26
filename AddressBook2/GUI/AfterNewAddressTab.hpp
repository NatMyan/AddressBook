#ifndef AFTER_NEW_ADDRESS_TAB_HPP
#define AFTER_NEW_ADDRESS_TAB_HPP

#include "../DataLayer/TableModel.hpp"
#include "../Logic/DatabaseManager.hpp"

#include <QWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QItemSelection>

class AfterNewAddressTab : public QTabWidget {
    Q_OBJECT

    public:
        AfterNewAddressTab(QWidget *parent = nullptr);
        void readFromDatabase();
        void writeToDatabase();

    public slots:
        void addEntry();
        void openEntry();
        void addNewEntry();
        void openNewEntry();
        void addEntry(const QString &name, const QString &phone, const QString &email);
        void openEntry(const QString &filePath);
        void showAddEntryDialog();
        void showOpenEntryDialog();

    signals:
        void selectionChanged (const QItemSelection &selected);
        // void sendDetails(const QString &name, const QString &phone, const QString &email);
        // void sendFilePath(const QString &filePath);
    
    private:
        void setupTabs();
        DatabaseManager *dbManager;
        TableModel *table;
        QPushButton *addButton;
        QPushButton *openButton;
        QSqlDatabase db;
};

#endif // AFTER_NEW_ADDRESS_TAB_HPP