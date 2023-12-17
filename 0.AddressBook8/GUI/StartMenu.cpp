#include "StartMenu.hpp"

StartMenu::StartMenu(QWidget *parent) : 
    QWidget(parent) 
{
    setupUi();
}

void StartMenu::setupUi() {
    auto descriptionLabel = new QLabel(tr("Address Book"));

    auto signInButton = new QPushButton(tr("Sign In"));
    auto signUpButton = new QPushButton(tr("Sign Up"));

    connect(signInButton, &QPushButton::clicked, this, &StartMenu::onSignInClicked);
    connect(signUpButton, &QPushButton::clicked, this, &StartMenu::onSignUpClicked);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(signInButton, 0, Qt::AlignHCenter);
    mainLayout->addWidget(signUpButton, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}

void StartMenu::onSignInClicked() {
    emit sigSignInClicked();
}

void StartMenu::onSignUpClicked() {
    emit sigSignUpClicked();
}
