#include "database.hpp"

int callback(void* data, int argc, char** argv, char** /*azColName*/) {
    std::vector<std::string>* produtos = static_cast<std::vector<std::string>*>(data);

    for (int i = 0; i < argc; i++) {
        produtos->push_back(argv[i]);
    }

    return 0;
}

DatabaseManager::DatabaseManager(const std::string& dbPath) {
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        std::cout << "Erro ao abrir o banco de dados." << std::endl;
    }
}

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

std::vector<std::string> DatabaseManager::buscarProdutos() {
    std::vector<std::string> produtos;

    std::string sql = "SELECT nome FROM produtos";

    char* errorMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), callback, &produtos, &errorMsg) != SQLITE_OK) {
        std::cout << "Erro ao executar a consulta SQL: " << errorMsg << std::endl;
        sqlite3_free(errorMsg);
    }

    return produtos;
}

