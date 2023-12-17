#include "SignUpMenu.hpp"

SignUpMenu::SignUpMenu(QWidget *parent) : QWidget(parent) {
    setupUi();
    connect(usernameEdit_, &QLineEdit::returnPressed, this, &SignUpMenu::onSignUpButtonClicked);
    connect(passwordEdit_, &QLineEdit::returnPressed, this, &SignUpMenu::onSignUpButtonClicked);
    connect(confirmPasswordEdit_, &QLineEdit::returnPressed, this, &SignUpMenu::onSignUpButtonClicked);
    connect(signUpButton_, &QPushButton::clicked, this, [this] {
        QString username = usernameEdit_->text();
        QString password = passwordEdit_->text();
        emit sigSignUp(username, password);
    });
    connect(cancelButton_, &QPushButton::clicked, this, &SignUpMenu::onCancelButtonClicked);
}

void SignUpMenu::setupUi() {
    auto usernameLabel = new QLabel(tr("Username:"));
    auto passwordLabel = new QLabel(tr("Password:"));
    auto confirmPasswordLabel = new QLabel(tr("Confirm Password:"));

    usernameEdit_ = new QLineEdit;
    passwordEdit_ = new QLineEdit;
    confirmPasswordEdit_ = new QLineEdit;

    passwordEdit_->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit_->setEchoMode(QLineEdit::Password);

    signUpButton_ = new QPushButton(tr("Sign Up"));
    cancelButton_ = new QPushButton(tr("Cancel"));

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameEdit_);

    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordEdit_);

    mainLayout->addWidget(confirmPasswordLabel);
    mainLayout->addWidget(confirmPasswordEdit_);
    
    mainLayout->addWidget(signUpButton_);
    mainLayout->addWidget(cancelButton_);

    setLayout(mainLayout);
}

void SignUpMenu::onSignUpButtonClicked() {
    QString username = usernameEdit_->text();
    QString password = passwordEdit_->text();
    QString confirmPassword = confirmPasswordEdit_->text();

    if (password == confirmPassword) {
        emit sigSignUp(username, password);
    } 
    else {
        qDebug() << "Passwords do not match!";
    }
}

void SignUpMenu::onCancelButtonClicked() {
    emit sigCancelClicked();
}