#ifndef TAB_NAMES_HPP
#define TAB_NAMES_HPP

#include <QVector>
#include <QString>

class TabNames {
    public:
        static QVector<QString> getTabNames();
        static void addTabName(const QString& newTabName);
        static void reset();

    private:
        static QVector<QString> tabNames_;
};

#endif // TAB_NAMES_HPP