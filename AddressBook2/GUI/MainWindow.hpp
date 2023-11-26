#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "AddressWidget.hpp"

#include <QItemSelection>
#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow();

    private slots:
        void updateActions(const QItemSelection &selection);
        void openFile();
        void saveFile();

    private:
        void createMenus();

        AddressWidget *addressWidget;
        // BeginningMenu *startMenu;
        QAction *editAct;
        QAction *removeAct;
        QAction *saveAct; 
};

#endif // MAIN_WINDOW_HPP