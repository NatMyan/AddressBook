#include "NewAddressTab.hpp"
#include "AddDialog.hpp"
#include "OpenDialog.hpp"

#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

NewAddressTab::NewAddressTab(QWidget *parent) : 
    QWidget(parent)
{
    auto descriptionLabel = new QLabel(tr(  "            There are currently no contacts in your address book.        "
                                          "\nClick 'Add' to add new contacts or 'Open' to open an existing database."));

    auto addButton = new QPushButton(tr("Add"));
    auto openButton = new QPushButton(tr("Open"));

    connect(addButton, &QAbstractButton::clicked, this, &NewAddressTab::addEntry);
    connect(openButton, &QAbstractButton::clicked, this, &NewAddressTab::openEntry);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(addButton, 0, Qt::AlignHCenter); 
    mainLayout->addWidget(openButton, 0, Qt::AlignHCenter); 

    setLayout(mainLayout);
}

void NewAddressTab::addEntry() {
    AddDialog aDialog;
    if (aDialog.exec())
        emit sendDetails(aDialog.name(), aDialog.phone(), aDialog.email());
}

void NewAddressTab::openEntry() {
    OpenDialog oDialog;
    if (oDialog.exec()) 
        emit sendFilePath(oDialog.getSelectedFilePath());
}