#include "AddDialog.hpp"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

AddDialog::AddDialog(QWidget *parent) : 
    QDialog(parent),
    nameText(new QLineEdit),
    phoneText(new QTextEdit),
    emailText(new QTextEdit)
{
    auto nameLabel = new QLabel(tr("Name"));
    auto phoneLabel = new QLabel(tr("Phone"));
    auto emailLabel = new QLabel(tr("Email"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    /// NOTE: col 1 and 2 will have 2x stretch than other cols
    gLayout->setColumnStretch(1, 2); 
    gLayout->setColumnStretch(2, 2);

    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(phoneLabel, 1, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(phoneText, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(emailLabel, 2, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(emailText, 2, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 3, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Contact"));
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

void AddDialog::editAddress(const QString &name, const QString &phone, const QString &email) {
    nameText->setReadOnly(true);
    nameText->setText(name);
    phoneText->setPlainText(phone);
    emailText->setPlainText(email);
}
