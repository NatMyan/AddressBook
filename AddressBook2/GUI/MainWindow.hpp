#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "AddressWidget.hpp"
#include "NewAddressTab.hpp"
#include "AfterNewAddressTab.hpp"

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
        void showAddressWidget();

    private:
        void createMenus();

        AddressWidget *addressWidget;
        AfterNewAddressTab *afterNewAddrTab;
        NewAddressTab *startMenu;
        QAction *editAct;
        QAction *removeAct;
        QAction *saveAct; 
};

#endif // MAIN_WINDOW_HPP