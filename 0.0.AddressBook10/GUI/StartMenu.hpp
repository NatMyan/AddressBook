#ifndef START_MENU_HPP
#define START_MENU_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class StartMenu : public QWidget {
    Q_OBJECT

    public:
        StartMenu(QWidget* parent = nullptr);

    signals:
        void sigSignInClicked();
        void sigSignUpClicked();

    private:
        void setupUi();

    private slots:
        void onSignInClicked();
        void onSignUpClicked();
};

#endif // START_MENU_HPP
