/*#include "OpenDialog.hpp"

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

OpenDialog::OpenDialog(QWidget *parent) : 
    QDialog(parent),
    filePath(new QLineEdit)
{
    setupUi();
}

QString OpenDialog::getSelectedFilePath() const {
    return filePath->text();
}

void OpenDialog::onOpenButtonClicked() {
    QString selectedFile = QFileDialog::getOpenFileName(this, tr("Open Address Book"), QDir::homePath(), tr("Data files (*.db)"));
    // filePath->setText(selectedFile);
    // QString filePath = QFileDialog::getOpenFileName(this, "Open Address Book", "", "SQLite Database (*.db *.sqlite)");
    //if (!filePath.isEmpty()) {
        // openDatabase(filePath);
    // }
    // accept();
}

void OpenDialog::setupUi() {
    // setFileMode(QFileDialog::ExistingFile);
    // setNameFilter("Data files (*.db)");
    // setAcceptMode(QFileDialog::AcceptOpen);

    auto fileLabel = new QLabel(tr("File Path"));
    
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;

    gLayout->setColumnStretch(0, 2); 
    gLayout->setColumnStretch(1, 2);

    gLayout->addWidget(fileLabel, 0, 0);
    gLayout->addWidget(filePath, 0, 1);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);
    // connect(this, &QFileDialog::fileSelected, this, &OpenDialog::open);

    connect(okButton, &QPushButton::clicked, this, &OpenDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &OpenDialog::reject);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Open Address Book"));

    // QString selectedFile = QFileDialog::getOpenFileName(this, tr("Open Address Book"), QDir::homePath(), tr("Data files (*.db)"));
    // filePath->setText(selectedFile);
}*/

/*
    auto nameLabel = new QLabel(tr("Name"));
    auto phoneLabel = new QLabel(tr("Phone"));
    auto emailLabel = new QLabel(tr("Email"));
    
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
   
    gLayout->setRowStretch(0, 3);
    gLayout->setRowStretch(1, 3);
    gLayout->setRowStretch(2, 3);

    /// NOTE: col 1 and 2 will have 3x stretch than other cols
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

*/