// AddressBookTab.cpp
#include "AddressBookTab.hpp"
#include "AddDialog.hpp"
#include "OpenDialog.hpp"

#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

AddressBookTab::AddressBookTab(QWidget *parent) : QWidget(parent) {
    auto descriptionLabel = new QLabel(tr("There are currently no contacts in your address book. "
                                         "\nClick 'Add' to add new contacts or 'Open' to open an existing database."));

    auto addButton = new QPushButton(tr("Add"));
    auto openButton = new QPushButton(tr("Open"));

    connect(addButton, &QAbstractButton::clicked, this, &AddressBookTab::addEntry);
    connect(openButton, &QAbstractButton::clicked, this, &AddressBookTab::openEntry);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(addButton, 0, Qt::AlignHCenter);
    mainLayout->addWidget(openButton, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}

void AddressBookTab::addEntry() {
    AddDialog aDialog;
    if (aDialog.exec())
        emit sendDetails(aDialog.name(), aDialog.phone(), aDialog.email());
}

void AddressBookTab::openEntry() {
    OpenDialog oDialog;
    if (oDialog.exec())
        emit sendFilePath(oDialog.getSelectedFilePath());
}
