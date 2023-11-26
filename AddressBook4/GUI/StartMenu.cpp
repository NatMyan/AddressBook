#include "StartMenu.hpp"

StartMenu::StartMenu(QWidget *parent = nullptr) : QWidget(parent) {
    setupUi();
}

void StartMenu::setupUi() {
    auto descriptionLabel = new QLabel(tr("There are currently no contacts in your address book. Click 'Add' to add new contacts or 'Open' to open an existing database."));

    auto addButton = new QPushButton(tr("Add"));
    auto openButton = new QPushButton(tr("Open"));

    connect(addButton, &QPushButton::clicked, this, &StartMenu::onAddClicked);
    connect(openButton, &QPushButton::clicked, this, &StartMenu::onOpenClicked);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(addButton, 0, Qt::AlignHCenter);
    mainLayout->addWidget(openButton, 0, Qt::AlignHCenter);

    setLayout(mainLayout);
}

void StartMenu::onAddClicked() {
    emit addClicked();
}

void StartMenu::onOpenClicked() {
    emit openClicked();
}
