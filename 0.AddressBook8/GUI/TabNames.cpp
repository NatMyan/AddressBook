#include "TabNames.hpp"

QVector<QString> TabNames::tabNames_ = {"Family", "Friends", "Co-Workers"};

QVector<QString> TabNames::getTabNames() {
    return tabNames_;
}

void TabNames::addTabName(const QString& newTabName) {
    tabNames_.append(newTabName);
}


