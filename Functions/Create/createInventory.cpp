#include "DatabaseConnector.h"
#include "Inventory.h"

bool createInventory(DatabaseConnector &db, const Inventory &inventory) {
    try {
        std::string query = "INSERT INTO Inventory (Quantity_Per_Vehicle, Model_Info) VALUES (?, ?)";
        std::unique_ptr<sql::PreparedStatement> pstmt(db.prepareStatement(query));
        pstmt->setInt(1, inventory.getQuantityPerVehicle());
        pstmt->setString(2, inventory.getModelInfo());
        pstmt->executeUpdate();
        return true;
    } catch (sql::SQLException &e) {
        // Handle error
        return false;
    }
}
