#ifndef TAB_NAMESS_HPP
#define TAB_NAMESS_HPP

#include <QVector>
#include <QString>

class TabNames {
    public:
        static QVector<QString> getTabNames();
        static void addTabName(const QString& newTabName);

    private:
        static QVector<QString> tabNames_;
};

#endif // TAB_NAMESS_HPP