#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

class SearchDialog : public QDialog {
    Q_OBJECT

    public:
        SearchDialog(QWidget *parent = nullptr);

    public:
        QString getSearchName() const;
        QString getSearchOption() const;

    private slots:
        void onSearchButtonClicked();
        void onCancelButtonClicked();

    private:
        void setupUi();

    private:
        QLineEdit *searchNameLineEdit;
        QComboBox *searchOptionComboBox;
};

/*
SearchDialog searchDialog;
if (searchDialog.exec() == QDialog::Accepted) {
    QString searchName = searchDialog.getSearchName();
    QString searchOption = searchDialog.getSearchOption();
    // Perform search operation with the entered search name and option
    // ...
}
*/