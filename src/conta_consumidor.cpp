#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "../include/conta_consumidor.hpp"

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

Consumidor::Consumidor(const std::string& usuario, const std::string& senha) : Conta(usuario, senha){
    // Recuperar os produtos comprados do banco de dados
    produtosComprados = getProdutosCompradosFromDB(usuario, db);

    // Fechar a conexão com o banco de dados
    sqlite3_close(db);
}

void Consumidor::adicionarProdutoComprado(const std::string& produto) {
    // Adicionar o produto à lista de produtos comprados
    produtosComprados.push_back(produto);

    // Atualizar o banco de dados com o novo produto comprado
    sqlite3* db;
    int rc = sqlite3_open("DATABASE.sqlite", &db);
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

void Consumidor::exibirProdutosComprados() const {
    std::cout << "Produtos comprados por " << usuario << ":" << std::endl;
    for (const auto& produto : produtosComprados) {
        std::cout << "- " << produto << std::endl;
    }
    
}