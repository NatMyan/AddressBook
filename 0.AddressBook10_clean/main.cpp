#include <QApplication>

#include "GUI/MainWindow.hpp"
#include "Controller.hpp"

int main(int argc, char *argv[]) {
    Controller a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

