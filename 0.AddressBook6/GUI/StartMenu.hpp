#ifndef START_MENU_HPP
#define START_MENU_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class StartMenu : public QWidget {
    Q_OBJECT

    public:
        StartMenu(QWidget *parent = nullptr);

    signals:
        void sigSignInClicked();
        void sigSignUpClicked();

    private:
        void setupUi();

    private slots:
        void onSignInClicked();
        void onSignUpClicked();
};

/*
StartMenu startMenu;
connect(&startMenu, &StartMenu::addClicked, this, &YourMainWindowClass::openAddDialog);
connect(&startMenu, &StartMenu::openClicked, this, &YourMainWindowClass::openOpenDialog);
*/

#endif // START_MENU_HPP