// AddressBookTab.hpp
#ifndef ADDRESSBOOKTAB_HPP
#define ADDRESSBOOKTAB_HPP

#include <QWidget>

class AddressBookTab : public QWidget {
    Q_OBJECT

public:
    AddressBookTab(QWidget *parent = nullptr);

public slots:
    void addEntry();
    void openEntry();

signals:
    void sendDetails(const QString &name, const QString &phone, const QString &email);
    void sendFilePath(const QString &filePath);
};

#endif // ADDRESSBOOKTAB_HPP
