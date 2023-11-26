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

#endif // CONTACT_HPP