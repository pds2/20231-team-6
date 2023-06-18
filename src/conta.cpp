#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "conta.hpp"

using namespace std;

void Conta::registrar(string usuario, string senha) {
    // Estabelecer conexão com o banco de dados
    sqlite3* db;
    int rc = sqlite3_open("DATABASE.sqlite", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Inserir um usuário no banco de dados
    std::string sql = "INSERT INTO usuarios (usuario, senha) VALUES ('" + usuario + "', '" + senha + "')";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao inserir usuário no banco de dados: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Usuário inserido com sucesso!" << std::endl;
    }

    // Fechar a conexão com o banco de dados
    sqlite3_close(db);
}

// Função de callback para recuperar os produtos comprados do banco de dados
int callbackProdutos(void* data, int argc, char** argv, char** /* azColName */) {
    std::vector<std::string>* produtos = reinterpret_cast<std::vector<std::string>*>(data);

    for (int i = 0; i < argc; i++) {
        produtos->push_back(argv[i]);
    }

    return 0;
}

Conta::Conta(const std::string& usuario, const std::string& senha) : usuario(usuario), senha(senha) {
    // Estabelecer conexão com o banco de dados
    sqlite3* db;
    int rc = sqlite3_open("DATABASE.sqlite", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        // Lidar com o erro adequadamente
    }
}

std::string Conta::getUsuario() const {
    return usuario;
}

bool Conta::verificarSenha(const std::string& senha) const {
    return this->senha == senha;
}
