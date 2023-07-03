#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <map>

class Database {
private:
    sqlite3* db;

public:
    Database(const std::string& nome_db);
    ~Database();

    std::vector<std::string> buscar_produtos();
    
};

#endif  // DATABASE_HPP

