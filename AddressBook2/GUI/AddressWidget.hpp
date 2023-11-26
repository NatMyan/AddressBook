#ifndef ADDRESS_WIDGET_HPP
#define ADDRESS_WIDGET_HPP

#include "NewAddressTab.hpp"
#include "../DataLayer/TableModel.hpp"
#include "../Logic/DatabaseManager.hpp"

#include <QItemSelection>
#include <QPushButton>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QTabWidget>

class AddressWidget : public QTabWidget {
    Q_OBJECT

    public:
        AddressWidget(QWidget *parent = nullptr);
        void readFromDatabase();
        void writeToDatabase();

    public slots:
        void showAddEntryDialog();
        void showOpenEntryDialog();
        void addEntry(const QString &name, const QString &phone, const QString &email);
        void openEntry(const QString &filePath);
        void editEntry();
        void removeEntry();
        void addNewEntry();
        void openNewEntry();
        // void addDynamicTab(const QString &tabName);

    signals:
        void selectionChanged (const QItemSelection &selected);

    // private slots:
        // void setupTabs();
        // void handleTabChange(int tabIndex);

    private:
        void setupTabs();

        inline static QString fileName = 
            QStandardPaths::standardLocations(QStandardPaths::TempLocation).value(0) + QStringLiteral("/addressbook.dat");
        TableModel *table;
        DatabaseManager *dbManager;
        NewAddressTab *newAddressTab;
        QPushButton *addButton;
        QPushButton *openButton;
        QSqlDatabase db;
};

#endif // ADDRESS_WIDGET_HPP