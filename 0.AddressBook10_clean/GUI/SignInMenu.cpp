#include "SignInMenu.hpp"
#include "StartMenu.hpp"

SignInMenu::SignInMenu(QWidget* parent) : QWidget(parent) {
    setupUi();
    connect(usernameEdit_, &QLineEdit::returnPressed, this, &SignInMenu::onSignInButtonClicked);
    connect(passwordEdit_, &QLineEdit::returnPressed, this, &SignInMenu::onSignInButtonClicked);
    // connect(signInButton_, &QPushButton::clicked, this, &SignInMenu::onSignInButtonClicked);
    connect(signInButton_, &QPushButton::clicked, this, [this] {
        QString username = usernameEdit_->text();
        QString password = passwordEdit_->text();
        emit sigSignIn(username, password);
    });
    connect(cancelButton_, &QPushButton::clicked, this, &SignInMenu::onCancelButtonClicked);
}

void SignInMenu::setupUi() {
    auto usernameLabel = new QLabel(tr("Username:"));
    auto passwordLabel = new QLabel(tr("Password:"));

    usernameEdit_ = new QLineEdit;
    passwordEdit_ = new QLineEdit;
    passwordEdit_->setEchoMode(QLineEdit::Password);

    signInButton_ = new QPushButton(tr("Sign In"));
    cancelButton_ = new QPushButton(tr("Cancel"));

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameEdit_);

    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordEdit_);
    
    mainLayout->addWidget(signInButton_);
    mainLayout->addWidget(cancelButton_);

    setLayout(mainLayout);
}

void SignInMenu::onSignInButtonClicked() {
    QString username = usernameEdit_->text();
    QString password = passwordEdit_->text();

    setTableName(username);
    user_.setName(username);
    emit sigSignIn(username, password);
}

void SignInMenu::onCancelButtonClicked() {
    emit sigCancelClicked();
}

void SignInMenu::setTableName(const QString& name) {
    tableName_ = name;
}

QString SignInMenu::getTableName() {
    return tableName_;
}

/*
void SignUpMenu::onSignUpButtonClicked() {
    QString username = usernameEdit_->text();
    QString password = passwordEdit_->text();
    QString confirmPassword = confirmPasswordEdit_->text();

    if (password == confirmPassword) {
        // Get the table name from user input or other logic
        QString tableName = determineTableName(username);
        emit sigSignUp(username, password, tableName);
    } else {
        qDebug() << "Passwords do not match!";
    }
}

void SignInMenu::onSignInButtonClicked() {
    QString username = usernameEdit_->text();
    QString password = passwordEdit_->text();

    // Get the table name from user input or other logic
    QString tableName = determineTableName(username);
    emit sigSignIn(username, password, tableName);
}

*/