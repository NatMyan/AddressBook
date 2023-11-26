#include "SaveDialog.hpp"

SaveDialog::SaveDialog(QWidget *parent) : 
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
}
