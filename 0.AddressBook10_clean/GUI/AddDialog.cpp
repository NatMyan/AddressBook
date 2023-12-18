#include "AddDialog.hpp"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

AddDialog::AddDialog(QWidget* parent) : 
    QDialog(parent),
    nameText_(new QLineEdit),
    phoneText_(new QTextEdit),
    emailText_(new QTextEdit),
    tabComboBox_(new QComboBox)
{   
    setupUi();
    connect(okButton_, &QAbstractButton::clicked, this, &AddDialog::onOkButtonClicked);
    connect(cancelButton_, &QAbstractButton::clicked, this, &QDialog::reject);
}

void AddDialog::onOkButtonClicked() {
    QString name = nameText_->text();
    QString phone = phoneText_->toPlainText();
    QString email = emailText_->toPlainText();
    QString tab = tabComboBox_->currentText();
    emit contactAdded(name, phone, email, tab);
    qDebug() << "Contact added signal emission";
    accept();
}

QString AddDialog::name() const {
    return nameText_->text();
}

QString AddDialog::phone() const {
    return phoneText_->toPlainText();
}

QString AddDialog::email() const {
    return emailText_->toPlainText();
}

QString AddDialog::selectedTab() const {
    return tabComboBox_->currentText();
}

void AddDialog::updateTabs(const TabNames& tabNames) {
    tabComboBox_->clear();
    for (const auto& tabName : tabNames.getTabNames()) {
        tabComboBox_->addItem(tabName);
    }
}

void AddDialog::updateTabs2() {
    tabComboBox_->clear();
    for (const auto& tabName : tabNames_.getTabNames()) {
        tabComboBox_->addItem(tabName);
    }
}

void AddDialog::updateTabNames(const QString& tabName) {
    tabComboBox_->addItem(tabName);
}

void AddDialog::editAddress(const Contact& contact) {
    nameText_->setText(contact.name);
    phoneText_->setPlainText(contact.phone);
    emailText_->setPlainText(contact.email);
    tabComboBox_->setCurrentText(contact.belonging);
}

void AddDialog::setupUi() {
    auto nameLabel = new QLabel(tr("Name"));
    auto phoneLabel = new QLabel(tr("Phone"));
    auto emailLabel = new QLabel(tr("Email"));
    auto tabLabel = new QLabel(tr("Tab"));

    okButton_ = new QPushButton(tr("OK"));
    cancelButton_ = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
   
    gLayout->setRowStretch(0, 30);
    gLayout->setRowStretch(1, 30);
    gLayout->setRowStretch(2, 30);
    gLayout->setRowStretch(3, 30);

    gLayout->setColumnStretch(1, 20); 
    gLayout->setColumnStretch(2, 20);
    gLayout->setColumnStretch(3, 20);

    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText_, 0, 1);

    gLayout->addWidget(phoneLabel, 1, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(phoneText_, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(emailLabel, 2, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(emailText_, 2, 1, Qt::AlignLeft);

    updateTabs(tabNames_);

    gLayout->addWidget(tabLabel, 3, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(tabComboBox_, 3, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton_);
    buttonLayout->addWidget(cancelButton_);

    gLayout->addLayout(buttonLayout, 4, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Add a Contact"));
}


