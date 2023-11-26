#ifndef NEW_ADDRESS_TAB_HPP
#define NEW_ADDRESS_TAB_HPP

#include <QWidget>

class NewAddressTab : public QWidget {
    Q_OBJECT

    public:
        NewAddressTab(QWidget *parent = nullptr);

    public slots:
        void addEntry();

    signals:
        void sendDetails(const QString &name, const QString &phone, const QString &email);
};

// #include "NewAddressTab.moc"

#endif // NEW_ADDRESS_TAB_HPP