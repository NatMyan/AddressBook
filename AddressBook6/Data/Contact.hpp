#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <QString>

struct Contact {
    QString name;
    QString phone;
    QString email;
    QString belonging; // tab
    
    bool operator==(const Contact &other) const {
        return name == other.name && 
               phone == other.phone && 
               email == other.email &&
               belonging == other.belonging;
    }
};

#endif // CONTACT_HPP