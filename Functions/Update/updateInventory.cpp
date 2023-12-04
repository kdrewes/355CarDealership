#include "DatabaseConnector.h"
#include "Inventory.h"

bool updateInventory(DatabaseConnector &db, const Inventory &inventory) {
    try {
        std::string query = "UPDATE Inventory SET Quantity_Per_Vehicle = ?, Model_Info = ? WHERE Inventory_ID = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(db.prepareStatement(query));
        pstmt->setInt(1, inventory.getQuantityPerVehicle());
        pstmt->setString(2, inventory.getModelInfo());
        pstmt->setInt(3, inventory.getInventoryID());
        pstmt->executeUpdate();
        return true;
    } catch (sql::SQLException &e) {
        // Handle error
        return false;
    }
}
