#include "AddDialog.hpp"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

AddDialog::AddDialog(QWidget *parent) : 
    QDialog(parent),
    nameText(new QLineEdit),
    phoneText(new QTextEdit),
    emailText(new QTextEdit),
    tabText(new QLineEdit)
{
    setupUi();
}

QString AddDialog::name() const {
    return nameText->text();
}

QString AddDialog::phone() const {
    return phoneText->toPlainText();
}

QString AddDialog::email() const {
    return emailText->toPlainText();
}

QString AddDialog::tab() const {
    return tabText->text();
}

/*QString AddDialog::selectedTab() const {
    return tabComboBox->currentText();
}*/

/*void AddDialog::updateTabs(const QTabWidget *tabs) {
    if (!tabs) {
        return;
    }
    tabComboBox->clear();
    for (int i = 0; i < tabs->count(); ++i) {
        QString tabText = tabs->tabText(i);
        tabComboBox->addItem(tabText);
    }
}*/

void AddDialog::editAddress(const QString &name, const QString &phone, const QString &email, const QString& tab) {
    // nameText->setReadOnly(true);
    nameText->setText(name);
    phoneText->setPlainText(phone);
    emailText->setPlainText(email);
    tabText->setText(tab);
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
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(phoneLabel, 1, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(phoneText, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(emailLabel, 2, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(emailText, 2, 1, Qt::AlignLeft);

    gLayout->addWidget(tabLabel, 3, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(tabText, 3, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 4, 1, Qt::AlignRight);

    // tabComboBox = new QComboBox(this);  

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, [this]() {
        emit contactAdded(name(), phone(), email(), tab());
        accept();
    });

    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    /*connect(this, &QDialog::finished, this, [this](int result) {
        if (result == QDialog::Accepted) {
            emit contactAdded(name(), phone(), email(), tab());
        }
    });*/
    

    setWindowTitle(tr("Add a Contact"));

    // connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    // connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    // setWindowTitle(tr("Add a Contact"));
}