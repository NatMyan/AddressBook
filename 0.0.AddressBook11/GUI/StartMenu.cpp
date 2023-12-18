#include "StartMenu.hpp"

StartMenu::StartMenu(QWidget* parent) : 
    QWidget(parent) 
{
    setupUi();
    connect(signInButton_, &QPushButton::clicked, this, &StartMenu::onSignInClicked);
    connect(signUpButton_, &QPushButton::clicked, this, &StartMenu::onSignUpClicked);
}

void StartMenu::setupUi() {
    auto descriptionLabel = new QLabel(tr("Address Book"));

    signInButton_ = new QPushButton(tr("Sign In"));
    signUpButton_ = new QPushButton(tr("Sign Up"));

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(signInButton_, 0, Qt::AlignHCenter);
    mainLayout->addWidget(signUpButton_, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}

void StartMenu::onSignInClicked() {
    emit sigSignInClicked();
}

void StartMenu::onSignUpClicked() {
    emit sigSignUpClicked();
}
