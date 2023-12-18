#ifndef USER_HPP
#define USER_HPP

#include <QString>

class User {
    public:
        static QString getName();
        static void setName(QString name);

    private:
        static QString userName_;
};

#endif // USER_HPP