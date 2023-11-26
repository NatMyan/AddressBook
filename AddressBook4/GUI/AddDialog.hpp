#ifndef ADD_DIALOG_HPP
#define ADD_DIALOG_HPP

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>

class AddDialog : public QDialog {
    Q_OBJECT

    public:
        AddDialog(QWidget *parent = nullptr);

    public:
        QString name() const;
        QString phone() const;
        QString email() const;
        void editAddress(const QString &name, const QString &phone, const QString &email);

    private:
        void setupUi();
    
    private:
        QLineEdit *nameText;
        QTextEdit *phoneText;
        QTextEdit *emailText;
};

#endif // ADD_DIALOG_HPP