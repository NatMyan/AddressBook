#ifndef SAVE_DIALOG_HPP
#define SAVE_DIALOG_HPP

#include <QFileDialog>
#include <QString>

class SaveDialog : public QDialog {
    Q_OBJECT

    public:
        SaveDialog(QWidget *parent = nullptr);
        QString getSelectedFilePath() const;

    public slots:
        void onSaveButtonClicked();
        void onCancelButtonClicked();
    
    private:
        void setupUi();

    private:
        QString selectedFilePath;
};

#endif // SAVE_DIALOG_HPP



/*SaveDialog saveDialog;
if (saveDialog.exec() == QDialog::Accepted) {
    QString filePath = saveDialog.getSelectedFilePath();
    // Perform save operation with the selected file path
    // ...
}*/

