#include "SearchDialog.hpp"

SearchDialog::SearchDialog(QWidget *parent) : 
    QDialog(parent) 
{
    setupUi();
}

QString SearchDialog::getSearchName() const {
    return searchNameLineEdit->text();
}

QString SearchDialog::getSearchOption() const {
    return searchOptionComboBox->currentText();
}

void SearchDialog::onSearchButtonClicked() {
    accept(); 
}

void SearchDialog::onCancelButtonClicked() {
    reject(); 
}

void SearchDialog::setupUi() {
    auto descriptionLabel = new QLabel(tr("Search for a contact:"));

    searchNameLineEdit = new QLineEdit;
    searchOptionComboBox = new QComboBox;
    searchOptionComboBox->addItems({"Name", "Phone", "Email"});

    auto searchButton = new QPushButton(tr("Search"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    connect(searchButton, &QAbstractButton::clicked, this, &SearchDialog::onSearchButtonClicked);
    connect(cancelButton, &QAbstractButton::clicked, this, &SearchDialog::onCancelButtonClicked);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(searchNameLineEdit, 0, Qt::AlignHCenter);
    mainLayout->addWidget(searchOptionComboBox, 0, Qt::AlignHCenter);
    mainLayout->addWidget(searchButton, 0, Qt::AlignHCenter);
    mainLayout->addWidget(cancelButton, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}
