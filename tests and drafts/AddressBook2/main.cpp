#include <QApplication>

#include "GUI/MainWindow.hpp"    
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mw;
    mw.show();
    return app.exec();
}
