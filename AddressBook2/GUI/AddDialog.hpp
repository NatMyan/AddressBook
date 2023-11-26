#ifndef ADD_DIALOG_HPP
#define ADD_DIALOG_HPP

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>

class AddDialog : public QDialog {
    Q_OBJECT

    public:
        AddDialog(QWidget *parent = nullptr);

        QString name() const;
        QString phone() const;
        QString email() const;
        void editAddress(const QString &name, const QString &phone, const QString &email);

    private:
        QLineEdit *nameText;
        QTextEdit *phoneText;
        QTextEdit *emailText;
};

#endif // ADD_DIALOG_HPP