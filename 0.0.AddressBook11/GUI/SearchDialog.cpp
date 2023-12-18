#include "SearchDialog.hpp"

SearchDialog::SearchDialog(QWidget* parent) : 
    QDialog(parent) 
{
    setupUi();
    connect(searchButton_, &QAbstractButton::clicked, this, &SearchDialog::onSearchButtonClicked);
    connect(cancelButton_, &QAbstractButton::clicked, this, &SearchDialog::onCancelButtonClicked);
}

QString SearchDialog::getSearchName() const {
    return searchNameLineEdit_->text();
}

QString SearchDialog::getSearchOption() const {
    return searchOptionComboBox_->currentText();
}

void SearchDialog::onSearchButtonClicked() {
    accept(); 
}

void SearchDialog::onCancelButtonClicked() {
    reject(); 
}

void SearchDialog::setupUi() {
    auto descriptionLabel = new QLabel(tr("Search for a contact:"));

    searchNameLineEdit_ = new QLineEdit;
    searchOptionComboBox_ = new QComboBox;
    searchOptionComboBox_->addItems({"Name", "Phone", "Email"});

    searchButton_ = new QPushButton(tr("Search"));
    cancelButton_ = new QPushButton(tr("Cancel"));

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(searchNameLineEdit_, 0, Qt::AlignHCenter);
    mainLayout->addWidget(searchOptionComboBox_, 0, Qt::AlignHCenter);
    mainLayout->addWidget(searchButton_, 0, Qt::AlignHCenter);
    mainLayout->addWidget(cancelButton_, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}
