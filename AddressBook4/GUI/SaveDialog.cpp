#include "SaveDialog.hpp"

#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

SaveDialog::SaveDialog(QWidget *parent) : 
    QDialog(parent) 
{
    setupUi();
}

QString SaveDialog::getSelectedFilePath() const {
    return selectedFilePath;
}

void SaveDialog::onSaveButtonClicked() {
    selectedFilePath = QFileDialog::getSaveFileName(this, "Save Address Book", "", "SQLite Database (*.db *.sqlite)");
    if (!selectedFilePath.isEmpty()) {
        accept(); // Close the dialog with QDialog::Accepted status
    } 
    else {
        QMessageBox::warning(this, "Warning", "Please select a valid file path.");
    }
}

void SaveDialog::onCancelButtonClicked() {
    reject(); // Close the dialog with QDialog::Rejected status
}

void SaveDialog::setupUi() {
    auto descriptionLabel = new QLabel(tr("Choose a location to save the address book:"));

    auto saveButton = new QPushButton(tr("Save"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    connect(saveButton, &QAbstractButton::clicked, this, &SaveDialog::onSaveButtonClicked);
    connect(cancelButton, &QAbstractButton::clicked, this, &SaveDialog::onCancelButtonClicked);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(saveButton, 0, Qt::AlignHCenter);
    mainLayout->addWidget(cancelButton, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}

/*SaveDialog::SaveDialog(QWidget *parent) : 
    QFileDialog(parent) 
{
    setFileMode(QFileDialog::AnyFile);
    setNameFilter("Data files (*.dat)");
    setAcceptMode(QFileDialog::AcceptSave);
    setWindowTitle("Save Address Book");
    connect(this, &QFileDialog::fileSelected, this, &SaveDialog::save);
}

QString SaveDialog::getSelectedFilePath() const {
    return selectedFilePath;
}

void SaveDialog::save() {
    selectedFilePath = selectedFiles().isEmpty() ? QString() : selectedFiles().first();
    accept();
}*/
