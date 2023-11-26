#include "MainWindow.hpp"

#include <QMenuBar>

MainWindow::MainWindow() : 
    QMainWindow(),
    addressWidget(new AddressWidget),
    startMenu(new NewAddressTab),
    afterNewAddrTab(new AfterNewAddressTab)
{
    setCentralWidget(startMenu);  // Initially set the central widget to startMenu
    createMenus();
    setWindowTitle(tr("Address Book"));
}

void MainWindow::createMenus() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAct = new QAction(tr("&Open..."), this);
    fileMenu->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

    saveAct = new QAction(tr("&Save"), this); 
    fileMenu->addAction(saveAct);
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);

    QMenu *toolMenu = menuBar()->addMenu(tr("&Tool"));
    editAct = new QAction(tr("&Edit Entry..."), this);
    editAct->setEnabled(false);
    toolMenu->addAction(editAct);
    connect(editAct, &QAction::triggered, this, &MainWindow::showAddressWidget);

    toolMenu->addSeparator();

    removeAct = new QAction(tr("&Remove Entry"), this);
    removeAct->setEnabled(false);
    toolMenu->addAction(removeAct);
    connect(removeAct, &QAction::triggered, addressWidget, &AddressWidget::removeEntry);

    connect(addressWidget, &AddressWidget::selectionChanged, this, &MainWindow::updateActions);
}

void MainWindow::openFile() {
    showAddressWidget();
    addressWidget->readFromDatabase();
}

void MainWindow::saveFile() {
    showAddressWidget();
    addressWidget->writeToDatabase();
}

void MainWindow::updateActions(const QItemSelection &selection) {
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty()) {
        removeAct->setEnabled(true);
        editAct->setEnabled(true);
    } 
    else {
        removeAct->setEnabled(false);
        editAct->setEnabled(false);
    }
}

void MainWindow::showAddressWidget() {
    setCentralWidget(addressWidget);
}


/*#include "MainWindow.hpp"

#include <QMenuBar>

MainWindow::MainWindow() : 
    QMainWindow(),
    addressWidget(new AddressWidget),
    startMenu(new NewAddressTab)
{
    // setCentralWidget(startMenu);
    setCentralWidget(addressWidget);
    createMenus();
    setWindowTitle(tr("Address Book"));
}

void MainWindow::createMenus() {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    // QMenu *fileMenu = startMenu;

    QAction *openAct = new QAction(tr("&Open..."), this);
    fileMenu->addAction(openAct);
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

    saveAct = new QAction(tr("&Save"), this); 
    fileMenu->addAction(saveAct);
    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);

    QMenu *toolMenu = menuBar()->addMenu(tr("&Tool"));
    editAct = new QAction(tr("&Edit Entry..."), this);
    editAct->setEnabled(false);
    toolMenu->addAction(editAct);
    connect(editAct, &QAction::triggered, addressWidget, &AddressWidget::editEntry);

    toolMenu->addSeparator();

    removeAct = new QAction(tr("&Remove Entry"), this);
    removeAct->setEnabled(false);
    toolMenu->addAction(removeAct);
    connect(removeAct, &QAction::triggered, addressWidget, &AddressWidget::removeEntry);

    connect(addressWidget, &AddressWidget::selectionChanged, this, &MainWindow::updateActions);
}

void MainWindow::openFile() {
    addressWidget->readFromDatabase();
}

void MainWindow::saveFile() {
    addressWidget->writeToDatabase();
}

void MainWindow::updateActions(const QItemSelection &selection) {
    QModelIndexList indexes = selection.indexes();

    if (!indexes.isEmpty()) {
        removeAct->setEnabled(true);
        editAct->setEnabled(true);
    } 
    else {
        removeAct->setEnabled(false);
        editAct->setEnabled(false);
    }
}*/

/*
void MainWindow::openFile(const QString &filePath) {
    OpenDialog openDialog(this);
    if (openDialog.exec() == QDialog::Accepted) {
        // Get the selected file path
        QString selectedFilePath = openDialog.getSelectedFilePath();

        // Implement the code to open the file at the selectedFilePath
        // You may want to call a function in the AddressWidget or another appropriate class to handle this
    }
}

void MainWindow::saveFile(const QString &filePath) {
    SaveDialog saveDialog(this);
    if (saveDialog.exec() == QDialog::Accepted) {
        // Get the selected file path
        QString selectedFilePath = saveDialog.getSelectedFilePath();

        // Implement the code to save the file at the selectedFilePath
        // You may want to call a function in the AddressWidget or another appropriate class to handle this
    }
}
*/