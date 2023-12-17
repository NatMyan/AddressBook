#include "SignUpMenu.hpp"

SignUpMenu::SignUpMenu(QWidget *parent) : QWidget(parent) {
    setupUi();
    connect(usernameEdit, &QLineEdit::returnPressed, this, &SignUpMenu::onSignUpButtonClicked);
    connect(passwordEdit, &QLineEdit::returnPressed, this, &SignUpMenu::onSignUpButtonClicked);
    connect(confirmPasswordEdit, &QLineEdit::returnPressed, this, &SignUpMenu::onSignUpButtonClicked);
    // connect(signUpButton, &QPushButton::clicked, this, &SignUpMenu::onSignUpButtonClicked);
    connect(signUpButton, &QPushButton::clicked, this, [this] {
        QString username = usernameEdit->text();
        QString password = passwordEdit->text();
        emit sigSignUp(username, password);
    });
    connect(cancelButton, &QPushButton::clicked, this, &SignUpMenu::onCancelButtonClicked);
}

void SignUpMenu::setupUi() {
    auto usernameLabel = new QLabel(tr("Username:"));
    auto passwordLabel = new QLabel(tr("Password:"));
    auto confirmPasswordLabel = new QLabel(tr("Confirm Password:"));

    usernameEdit = new QLineEdit;
    passwordEdit = new QLineEdit;
    confirmPasswordEdit = new QLineEdit;

    passwordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);

    signUpButton = new QPushButton(tr("Sign Up"));
    cancelButton = new QPushButton(tr("Cancel"));

    // connect(signUpButton, &QPushButton::clicked, this, &SignUpMenu::onSignUpButtonClicked);
    connect(signUpButton, &QPushButton::clicked, this, [this] {
        QString username = usernameEdit->text();
        QString password = passwordEdit->text();
        emit sigSignUp(username, password);
    });
    connect(cancelButton, &QPushButton::clicked, this, &SignUpMenu::onCancelButtonClicked);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameEdit);

    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordEdit);

    mainLayout->addWidget(confirmPasswordLabel);
    mainLayout->addWidget(confirmPasswordEdit);
    
    mainLayout->addWidget(signUpButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);
}

void SignUpMenu::onSignUpButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();

    if (password == confirmPassword) {
        emit sigSignUp(username, password);
    } 
    else {
        qDebug() << "Passwords do not match!";
    }
}

void SignUpMenu::onCancelButtonClicked() {
    // Emit the signal indicating cancel
    emit sigCancelClicked();
}