#include "SearchResultDialog.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

SearchResultDialog::SearchResultDialog(QVector<Contact> qVec, QWidget* parent) : 
    QDialog(parent),
    qVec_(qVec)
{
    showSearchResultDialog();
}

void SearchResultDialog::showSearchResultDialog() {
    setWindowTitle("Search Result");

    QVBoxLayout* fullLayout = new QVBoxLayout(this);
    if (!qVec_.empty()) {
        for (qsizetype i = 0; i < qVec_.size(); ++i) {
            QHBoxLayout* layout = new QHBoxLayout(this);
            
            QLabel* nameLabel = new QLabel("Name: " + qVec_.at(i).name);
            QLabel* phoneLabel = new QLabel("Phone: " + qVec_.at(i).phone);
            QLabel* emailLabel = new QLabel("Email: " + qVec_.at(i).email);
            QLabel* tabLabel = new QLabel("Tab: " + qVec_.at(i).belonging);

            layout->addWidget(nameLabel);
            layout->addWidget(phoneLabel);
            layout->addWidget(emailLabel);
            layout->addWidget(tabLabel);

            fullLayout->addLayout(layout);
        }
    }
    else {
        QHBoxLayout* layout = new QHBoxLayout(this);
        QLabel* notFoundLabel = new QLabel("No such contact exists");
        fullLayout->addLayout(layout);
    }
}

