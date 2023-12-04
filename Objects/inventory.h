#include <string>

class Inventory {
public:
    int inventoryID; // Primary Key
    int quantityPerVehicle;
    std::string modelInfo; // This should be a foreign key or an associative entity if it links to another table/model
};