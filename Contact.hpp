#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <vector>

struct Contact {
    std::string name_;
    std::vector<std::string> phoneNumber_;
    std::vector<std::string> email_;
    std::vector<std::string> additional_;
};

#endif // CONTACT_HPP