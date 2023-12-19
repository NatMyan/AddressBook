#ifndef SEARCH_DIALOG_HPP
#define SEARCH_DIALOG_HPP

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

    private:
        void setupUi();

    private:
        QLineEdit* searchNameLineEdit_;
        QComboBox* searchOptionComboBox_;
        QPushButton* cancelButton_;
        QPushButton* searchButton_;
};

#endif // SEARCH_DIALOG_HPP
