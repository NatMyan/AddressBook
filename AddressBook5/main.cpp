#include <QApplication>
// #include <QtSql/QSqlDatabase>
// #include <QtSql/QSqlError>

#include "GUI/MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    /*if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qWarning() << "SQLite driver not available.";
        return -1;
    }*/
    MainWindow w;
    w.show();
    return a.exec();
}