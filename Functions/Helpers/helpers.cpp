#include "helpers.h"

std::string timeToString(std::time_t time) {
    std::tm *tm = std::localtime(&time); // Convert to local time
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);
    return std::string(buffer);
}
