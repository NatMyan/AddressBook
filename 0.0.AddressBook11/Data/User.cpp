#include "User.hpp"

QString User::userName_ = "contacts";

QString User::getName() {
    return userName_;
}

void User::setName(QString name) {
    userName_ = name;
}
