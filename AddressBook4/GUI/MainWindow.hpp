#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "StartMenu.hpp"
#include "AddressBookInterface.hpp"
#include "../Logic/AddressBookLogic.hpp"

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private slots:
        void onAddClicked();
        void onOpenClicked();
        void onContactAdded(const QString &name, const QString &phone, const QString &email);
        void onContactEdited(int tabIndex, int rowIndex, const QString &name, const QString &phone, const QString &email);

    private:
        void setupUi();

    private:
        QStackedWidget *stackedWidget;
        StartMenu *startMenu;
        AddressBookInterface *addressBookInterface;
        AddressBookLogic *addressBookLogic;
};

#endif // MAIN_WINDOW_HPP

