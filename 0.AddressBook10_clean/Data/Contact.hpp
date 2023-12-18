#ifndef CONTACTT_HPP
#define CONTACTT_HPP

#include <QString>

struct Contact {
    QString name;
    QString phone;
    QString email;
    QString belonging; // tab
    
    bool operator==(const Contact &other) const {
        return (name == other.name && phone == other.phone && email == other.email && belonging == other.belonging);
    }

    bool operator!=(const Contact &other) const {
        return !((*this) == other);
    }
};

#endif // CONTACTT_HPP