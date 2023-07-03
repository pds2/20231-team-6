#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>

class DatabaseManager {
private:
    sqlite3* db;

public:
    DatabaseManager(const std::string& dbPath);
    ~DatabaseManager();

    std::vector<std::string> buscarProdutos();
};

#endif  // DATABASE_HPP

