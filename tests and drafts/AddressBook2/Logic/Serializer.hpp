/*
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../DataLayer/Contact.hpp"

#include <QDataStream>

inline QDataStream &operator<<(QDataStream &stream, const Contact &contact) {
    return stream << contact.name << contact.phone << contact.email;
}

inline QDataStream &operator>>(QDataStream &stream, Contact &contact) {
    return stream >> contact.name >> contact.phone >> contact.email;
}

#endif // SERIALIZER_HPP
*/

