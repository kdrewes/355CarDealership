#include <string>

class Sale {
public:
    int saleID; // Primary Key
    int empID; // Foreign Key referencing Employee
    int custID; // Foreign Key referencing Customer
    std::string vehicleIdentificationNumber; // Foreign Key referencing Vehicle
    double price;
    std::string saleDate;
};
