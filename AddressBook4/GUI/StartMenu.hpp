#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "AddDialog.hpp"
#include "OpenDialog.hpp"

class StartMenu : public QWidget {
    Q_OBJECT

    public:
        StartMenu(QWidget *parent = nullptr);

    signals:
        void addClicked();
        void openClicked();

    private:
        void setupUi();

    private slots:
        void onAddClicked();
        void onOpenClicked();
};

/*
StartMenu startMenu;
connect(&startMenu, &StartMenu::addClicked, this, &YourMainWindowClass::openAddDialog);
connect(&startMenu, &StartMenu::openClicked, this, &YourMainWindowClass::openOpenDialog);
*/