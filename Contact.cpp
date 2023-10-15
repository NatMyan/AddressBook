#include "Contact.hpp"

Contact::Contact(const std::string& name, const std::string& phoneNumber, const std::string& email)
        : name_(name), phoneNumber_(phoneNumber), email_(email) 
{}

std::string Contact::getName() const { 
    return name_; 
}

std::string Contact::getPhoneNumber() const { 
    return phoneNumber_; 
}
    
std::string Contact::getEmail() const { 
    return email_;
}