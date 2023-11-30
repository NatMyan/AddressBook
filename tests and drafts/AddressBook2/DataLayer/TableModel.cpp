#include "TableModel.hpp"

#include <QSqlError>
#include <QSqlQuery>

TableModel::TableModel(QObject *parent) : 
    QAbstractTableModel(parent)
{
    // readData();
}

TableModel::TableModel(const QList<Contact> &contacts, QObject *parent) : 
    QAbstractTableModel(parent), 
    contacts(contacts)
{
    // readData();
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : contacts.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return parent.isValid() ? 0 : 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= contacts.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &contact = contacts.at(index.row());

        switch (index.column()) {
            case 0:
                return contact.name;
            case 1:
                return contact.phone;
            case 2:
                return contact.email;
            default:
                break;
        }
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
            case 1:
                return tr("Phone");
            case 2:
                return tr("Email");
            default:
                break;
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index) {
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        contacts.insert(position, { QString(), QString(), QString() });

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index) {
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        contacts.removeAt(position);

    endRemoveRows();
    return true;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto contact = contacts.value(row);

        switch (index.column()) {
            case 0:
                contact.name = value.toString();
                break;
            case 1:
                contact.phone = value.toString();
                break;
            case 2:
                contact.email = value.toString();
                break;
            default:
                return false;
        }
        contacts.replace(row, contact);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

const QList<Contact> &TableModel::getContacts() const {
    return contacts;
}

/*bool TableModel::readData() {
    QSqlQuery query;
    if (query.exec("SELECT name, phone, email FROM contacts")) {
        // Clear existing data
        contacts.clear();

        while (query.next()) {
            Contact contact;
            contact.name = query.value(0).toString();
            contact.phone = query.value(1).toString();
            contact.email = query.value(2).toString();
            contacts.append(contact);
        }

        // Inform views that the data has changed
        // reset();
        return true;
    }

    qDebug() << "Error reading data:" << query.lastError().text();
    return false;
}

bool TableModel::writeData() {
    QSqlQuery query;
    if (query.exec("DELETE FROM contacts")) {
        for (const auto &contact : contacts) {
            query.prepare("INSERT INTO contacts (name, phone, email) VALUES (?, ?)");
            query.addBindValue(contact.name);
            query.addBindValue(contact.phone);
            query.addBindValue(contact.email);

            if (!query.exec()) {
                qDebug() << "Error writing data:" << query.lastError().text();
                return false;
            }
        }
        return true;
    }

    qDebug() << "Error clearing data:" << query.lastError().text();
    return false;
}
*/