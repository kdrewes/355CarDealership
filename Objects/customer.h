#include <string>

class Customer {
public:
    int customerID; // Primary Key
    std::string phoneNumber;
    std::string email;
    std::string address;
    std::string firstName;
    char middleInitial;
    std::string lastName;
};