#ifndef ADD_DIALOG_HPP
#define ADD_DIALOG_HPP

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>

class AddDialog : public QDialog {
    Q_OBJECT

    public:
        AddDialog(QWidget *parent = nullptr);

    public:
        QString name() const;
        QString phone() const;
        QString email() const;
        QString selectedTab() const;
        void editAddress(const QString &name, const QString &phone, const QString &email);
        // void updateTabs(const QTabWidget *tabs);

    signals:
        void contactAdded(const QString &name, const QString &phone, const QString &email, const QString &tab);
    
    private:
        void setupUi();
    
    private:
        QLineEdit *nameText;
        QTextEdit *phoneText;
        QTextEdit *emailText;
        QComboBox *tabComboBox;
};

#endif // ADD_DIALOG_HPP