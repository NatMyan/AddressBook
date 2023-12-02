#include "AddDialog.hpp"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

AddDialog::AddDialog(QWidget *parent) : 
    QDialog(parent),
    nameText_(new QLineEdit),
    phoneText_(new QTextEdit),
    emailText_(new QTextEdit),
    // tabText_(new QLineEdit),
    tabComboBox_(new QComboBox)
    // tables_(new Tables(nullptr, {"Family", "Friends", "Co-workers"}))
{   
    // tables_ = tables;
    setupUi();
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

/*QString AddDialog::tab() const {
    return tabText_->text();
}*/

QString AddDialog::selectedTab() const {
    return tabComboBox_->currentText();
}

/*void AddDialog::updateTabs(const QString& tabText) {
    tabComboBox_->addItem(tabText);
}*/

void AddDialog::updateTabs(const TabNames& tabNames) {
    tabComboBox_->clear();
    for (const auto& tabName : tabNames.getTabNames()) {
        tabComboBox_->addItem(tabName);
    }
}

void AddDialog::updateTabNames(const QString& tabName) {
    tabComboBox_->addItem(tabName);
}

void AddDialog::editAddress(const Contact& contact) {
    // nameText_->setReadOnly(true);
    nameText_->setText(contact.name);
    phoneText_->setPlainText(contact.phone);
    emailText_->setPlainText(contact.email);
    // tabText_->setText(contact.belonging);
    tabComboBox_->setCurrentText(contact.belonging);
}

void AddDialog::setupUi() {
    auto nameLabel = new QLabel(tr("Name"));
    auto phoneLabel = new QLabel(tr("Phone"));
    auto emailLabel = new QLabel(tr("Email"));
    auto tabLabel = new QLabel(tr("Tab"));

    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

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
    // gLayout->addWidget(tabText_, 3, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 4, 1, Qt::AlignRight);

    // tabComboBox = new QComboBox(this);  

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);

    /*connect(okButton, &QAbstractButton::clicked, this, [this]() {
        emit contactAdded(name(), phone(), email(), selectedTab());
        accept();
    });*/

    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Add a Contact"));

    /*connect(this, &QDialog::finished, this, [this](int result) {
        if (result == QDialog::Accepted) {
            emit contactAdded(name(), phone(), email(), tab());
        }
    });*/

    // connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    // connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    // setWindowTitle(tr("Add a Contact"));
}

/*void AddDialog::updateTabs(const QTabWidget *tabs) {
    if (!tabs) {
        return;
    }
    tabComboBox_->clear();
    for (int i = 0; i < tabs->count(); ++i) {
        QString tabText = tabs->tabText(i);
        tabComboBox_->addItem(tabText);
    }
}*/