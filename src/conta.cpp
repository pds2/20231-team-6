#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "conta.hpp"


// Função de callback para recuperar os produtos comprados do banco de dados
int callbackProdutos(void* data, int argc, char** argv, char** /* azColName */) {
    std::vector<std::string>* produtos = reinterpret_cast<std::vector<std::string>*>(data);

    for (int i = 0; i < argc; i++) {
        produtos->push_back(argv[i]);
    }

    return 0;
}

// Função para recuperar os produtos comprados do banco de dados para uma conta específica
std::vector<std::string> getProdutosCompradosFromDB(const std::string& usuario, sqlite3* db) {
    std::vector<std::string> produtos;
    std::string sql = "SELECT produto FROM produtos_comprados WHERE usuario = '" + usuario + "'";

    int rc = sqlite3_exec(db, sql.c_str(), callbackProdutos, &produtos, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao executar a consulta SQL: " << sqlite3_errmsg(db) << std::endl;
    }

    return produtos;
}

Conta::Conta(const std::string& usuario, const std::string& senha) : usuario(usuario), senha(senha) {
    // Estabelecer conexão com o banco de dados
    sqlite3* db;
    int rc = sqlite3_open("DATABASE.sqlite", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        // Lidar com o erro adequadamente
    }

    // Recuperar os produtos comprados do banco de dados
    produtosComprados = getProdutosCompradosFromDB(usuario, db);

    // Fechar a conexão com o banco de dados
    sqlite3_close(db);
}

std::string Conta::getUsuario() const {
    return usuario;
}

bool Conta::verificarSenha(const std::string& senha) const {
    return this->senha == senha;
}

void Conta::adicionarProdutoComprado(const std::string& produto) {
    // Adicionar o produto à lista de produtos comprados
    produtosComprados.push_back(produto);

    // Atualizar o banco de dados com o novo produto comprado
    sqlite3* db;
    int rc = sqlite3_open("meu_banco_de_dados.sqlite", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        // Lidar com o erro adequadamente
    }

    std::string sql = "INSERT INTO produtos_comprados (usuario, produto) VALUES ('" + usuario + "', '" + produto + "')";

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Erro ao executar a consulta SQL: " << sqlite3_errmsg(db) << std::endl;
        // Lidar com o erro adequadamente
    }

    sqlite3_close(db);
}

void Conta::exibirProdutosComprados() const {
    std::cout << "Produtos comprados por " << usuario << ":" << std::endl;
    for (const auto& produto : produtosComprados) {
        std::cout << "- " << produto << std::endl;
    }
    
}






