#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <QString>

struct Contact {
    QString name;
    QString phone;
    QString email;
    
    bool operator==(const Contact &other) const {
        return name == other.name && 
               phone == other.phone && 
               email == other.email;
    }
};

inline QDataStream &operator<<(QDataStream &stream, const Contact &contact) {
    return stream << contact.name << contact.phone << contact.email;
}

inline QDataStream &operator>>(QDataStream &stream, Contact &contact) {
    return stream >> contact.name >> contact.phone >> contact.email;
}

#endif // CONTACT_HPP