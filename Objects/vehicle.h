#include <string>

class Vehicle {
public:
    std::string vehicleIdentificationNumber; // Primary Key
    std::string manufacturer;
    std::string modelName;
    int modelYear;
    struct SelectedOptions {
        std::string engine;
        std::string transmission;
        std::string driveTrain;
    } options;
    std::string color;
    double price;
};