#ifndef START_MENU_HPP
#define START_MENU_HPP

#include "AddDialog.hpp"
#include "OpenDialog.hpp"

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class StartMenu : public QWidget {
    Q_OBJECT

    public:
        StartMenu(QWidget *parent = nullptr);

    signals:
        // void addClicked();
        void openClicked();

    private:
        void setupUi();

    private slots:
        // void onAddClicked();
        void onOpenClicked();
};

/*
StartMenu startMenu;
connect(&startMenu, &StartMenu::addClicked, this, &YourMainWindowClass::openAddDialog);
connect(&startMenu, &StartMenu::openClicked, this, &YourMainWindowClass::openOpenDialog);
*/

#endif // START_MENU_HPP