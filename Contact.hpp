#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    Contact(const std::string& name, const std::string& phoneNumber, const std::string& email);

    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getEmail() const;

private:
    std::string name_;
    std::string phoneNumber_;
    std::string email_;
};

#endif // CONTACT_HPP