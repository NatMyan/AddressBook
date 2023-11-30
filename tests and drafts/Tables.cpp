/*#include "Tables.hpp"

Tables::Tables(QWidget *parent, QVector<QTableWidget*> tables) :
    QTabWidget(parent),
    tables_(tables)
{}

void Tables::operator=(const Tables& other) {
    if (this != &other) {
        tables_.clear();

        for (const auto& table : other.tables_) {
            QTableWidget* newTable = new QTableWidget(table);
            tables_.append(newTable);
        }
    }
}

QVector<QTableWidget*> Tables::getTables() {
    return tables_;
}

void Tables::addTable (QTableWidget* table) {
    tables_.append(table);
}*/