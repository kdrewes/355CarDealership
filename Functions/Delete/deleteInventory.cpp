#include "DatabaseConnector.h"

bool deleteInventory(DatabaseConnector &db, int inventoryID) {
    try {
        std::string query = "DELETE FROM Inventory WHERE Inventory_ID = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(db.prepareStatement(query));
        pstmt->setInt(1, inventoryID);
        pstmt->executeUpdate();
        return true;
    } catch (sql::SQLException &e) {
        // Handle error
        return false;
    }
}
