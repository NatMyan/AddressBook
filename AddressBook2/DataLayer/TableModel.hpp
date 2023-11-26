#ifndef TABLE_MODEL_HPP
#define TABLE_MODEL_HPP

#include "Contact.hpp"

#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel {
    Q_OBJECT

    public:
        TableModel(QObject *parent = nullptr);
        TableModel(const QList<Contact> &contacts, QObject *parent = nullptr);

    public:
        int rowCount(const QModelIndex &parent) const override;
        int columnCount(const QModelIndex &parent) const override;
        QVariant data(const QModelIndex &index, int role) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
        Qt::ItemFlags flags(const QModelIndex &index) const override;
        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
        bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
        bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
        const QList<Contact> &getContacts() const;

    private:
        QList<Contact> contacts;
};

#endif // TABLE_MODEL_HPP