#include "SignInMenu.hpp"
#include "StartMenu.hpp"

SignInMenu::SignInMenu(QWidget *parent) : QWidget(parent) {
    setupUi();
    connect(usernameEdit, &QLineEdit::returnPressed, this, &SignInMenu::onSignInButtonClicked);
    connect(passwordEdit, &QLineEdit::returnPressed, this, &SignInMenu::onSignInButtonClicked);
    // connect(signInButton, &QPushButton::clicked, this, &SignInMenu::onSignInButtonClicked);
    connect(signInButton, &QPushButton::clicked, this, [this] {
        QString username = usernameEdit->text();
        QString password = passwordEdit->text();
        emit sigSignIn(username, password);
    });
    connect(cancelButton, &QPushButton::clicked, this, &SignInMenu::onCancelButtonClicked);
}

void SignInMenu::setupUi() {
    auto usernameLabel = new QLabel(tr("Username:"));
    auto passwordLabel = new QLabel(tr("Password:"));

    usernameEdit = new QLineEdit;
    passwordEdit = new QLineEdit;
    passwordEdit->setEchoMode(QLineEdit::Password);

    signInButton = new QPushButton(tr("Sign In"));
    cancelButton = new QPushButton(tr("Cancel"));

    connect(signInButton, &QPushButton::clicked, this, &SignInMenu::onSignInButtonClicked);
    connect(cancelButton, &QPushButton::clicked, this, &SignInMenu::onCancelButtonClicked);
    // connect(cancelButton, &QPushButton::clicked, this, &StartMenu::onCancelButtonClicked);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameEdit);

    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordEdit);
    
    mainLayout->addWidget(signInButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);
}

void SignInMenu::onSignInButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    emit sigSignIn(username, password);
}

void SignInMenu::onCancelButtonClicked() {
    emit sigCancelClicked();
}