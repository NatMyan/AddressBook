#ifndef ADDRESS_WIDGET_HPP
#define ADDRESS_WIDGET_HPP

#include "NewAddressTab.hpp"
#include "TableModel.hpp"

#include <QItemSelection>
#include <QPushButton>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QTabWidget>

class AddressWidget : public QTabWidget {
    Q_OBJECT

    public:
        AddressWidget(QWidget *parent = nullptr);
        // void readFromFile();
        // void writeToFile();

        void readFromDatabase();
        void writeToDatabase();

    public slots:
        void showAddEntryDialog();
        void addEntry(const QString &name, const QString &phone, const QString &email);
        void editEntry();
        void removeEntry();
        void addNewEntry();

    signals:
        void selectionChanged (const QItemSelection &selected);

    private:
        void setupTabs();

        inline static QString fileName = 
            QStandardPaths::standardLocations(QStandardPaths::TempLocation).value(0) + QStringLiteral("/addressbook.dat");
        TableModel *table;
        NewAddressTab *newAddressTab;
        QPushButton *addButton;
        QSqlDatabase db;
};

// #include "AddressWidget.moc"

#endif // ADDRESS_WIDGET_HPP