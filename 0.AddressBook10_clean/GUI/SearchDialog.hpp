#ifndef SEARCH_DIALOG_HPP
#define SEARCH_DIALOG_HPP

#include "../Data/User.hpp"

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

class SearchDialog : public QDialog {
    Q_OBJECT

    public:
        SearchDialog(QWidget* parent = nullptr);

    public:
        QString getSearchName() const;
        QString getSearchOption() const;

    private slots:
        void onSearchButtonClicked();
        void onCancelButtonClicked();
    
    signals:
        void sigAccepted(const QString& name, const QString& searchName, const QString& searchOption);

    private:
        void setupUi();

    private:
        QLineEdit* searchNameLineEdit_;
        QComboBox* searchOptionComboBox_;
        QPushButton* cancelButton_;
        QPushButton* searchButton_;
        User user_;
};

#endif // SEARCH_DIALOG_HPP

/*
SearchDialog searchDialog;
if (searchDialog.exec() == QDialog::Accepted) {
    QString searchName = searchDialog.getSearchName();
    QString searchOption = searchDialog.getSearchOption();
    // Perform search operation with the entered search name and option
    // ...
}
*/