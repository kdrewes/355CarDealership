#include "Db/DatabaseConnector/databaseconnector.h"

int main() {
    // Replace with your actual database credentials
    DatabaseConnector db("tcp://127.0.0.1:3306", "username", "password", "dbname");

    if (db.connect()) {
        // Example query
        sql::ResultSet* res = db.executeQuery("SELECT * FROM inventory");
        
        while (res && res->next()) {
            // Access column data by index, name or alias
            int inventoryID = res->getInt("Inventory_ID");
            int quantityPerVehicle = res->getInt("Quantity_Per_Vehicle");
            std::string modelInfo = res->getString("Model_Info");

            // Process data
        }
        delete res; // Remember to delete the result set
        db.disconnect();
    }

    return 0;
}
