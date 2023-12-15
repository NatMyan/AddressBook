#ifndef ADD_DIALOG_HPP
#define ADD_DIALOG_HPP

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>

#include "../Data/Contact.hpp"
#include "TabNames.hpp"

class AddDialog : public QDialog {
    Q_OBJECT

    public:
        AddDialog(QWidget *parent = nullptr);

    public:
        void editAddress(const Contact& contact);
        QString name() const;
        QString phone() const;
        QString email() const;
        QString selectedTab() const;
        void updateTabs2();
        void updateTabs(const TabNames& tabNames);
        void updateTabNames(const QString& tabName);
        // QString tab() const;
        // void updateTabs(const QString& tabText);
        // QString contact() const;
        // void updateTabs(const QTabWidget *tabs);
        // void updateTabs(const Tables& tables);
        // public slots:

    signals:
        void contactAdded(const QString &name, const QString &phone, const QString &email, const QString &tab);
    
    private:
        void setupUi();
    
    private:
        QLineEdit *nameText_;
        QTextEdit *phoneText_;
        QTextEdit *emailText_;
        // QLineEdit *tabText_;
        QComboBox *tabComboBox_;
        TabNames tabNames_;
        // Tables tables_;
};

#endif // ADD_DIALOG_HPP