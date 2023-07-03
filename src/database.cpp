#include "database.hpp"

int callback(void* data, int argc, char** argv, char** ) {
    std::vector<std::string>* produtos = static_cast<std::vector<std::string>*>(data);

    for (int i = 0; i < argc; i++) {
        produtos->push_back(argv[i]);
    }

    return 0;
}

int callback_precos(void* data, int argc, char** argv, char** ) {
    std::map<std::string, double>* produtosPrecos = reinterpret_cast<std::map<std::string, double>*>(data);

    std::string nome = argv[0];
    double preco = std::stod(argv[1]);

    (*produtosPrecos)[nome] = preco;

    return 0;
}


Database::Database(const std::string& nome_db) {
    if (sqlite3_open(nome_db.c_str(), &db) != SQLITE_OK) {
        std::cout << "Erro ao abrir o banco de dados." << std::endl;
    }
}

Database::~Database() {
    sqlite3_close(db);
}

std::vector<std::string> Database::buscar_produtos() {
    std::vector<std::string> produtos;

    std::string sql = "SELECT nome FROM produtos";

    char* errorMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), callback, &produtos, &errorMsg) != SQLITE_OK) {
        std::cout << "Erro ao executar a consulta SQL: " << errorMsg << std::endl;
        sqlite3_free(errorMsg);
    }

    return produtos;
}


std::map<std::string, float> get_produtos_preco_from_db(sqlite3* db) {
    std::map<std::string, float> produtos_preco;
    std::string sql = "SELECT nome, preco FROM produtos";

    int rc = sqlite3_exec(db, sql.c_str(), callback_produtos_preco, &produtos_preco, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao executar a consulta SQL: " << sqlite3_errmsg(db) << std::endl;
    }

    return produtos_preco;
}



