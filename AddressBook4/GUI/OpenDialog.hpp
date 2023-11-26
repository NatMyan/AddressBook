#ifndef OPEN_DIALOG_HPP
#define OPEN_DIALOG_HPP

#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QLineEdit>

class OpenDialog : public QDialog {
    Q_OBJECT

    public:
        OpenDialog(QWidget *parent = nullptr);

    public:
        QString getSelectedFilePath() const;

    public slots:
        void onOpenButtonClicked();

    private:
        void setupUi();

    private:
        QLineEdit *filePath;
};

#endif // OPEN_DIALOG_HPP
