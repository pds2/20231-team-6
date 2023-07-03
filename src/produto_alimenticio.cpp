#include "../include/produto_alimenticio.hpp"

#include <iostream>

ProdutoAlimenticio::ProdutoAlimenticio(const std::string &nome, double preco, int quantidade,
                                       bool vegano, int peso, const std::string &dataDeValidade)
    : Produto(nome, preco, quantidade), _vegano(vegano), _peso(peso), _dataDeValidade(dataDeValidade) {
    if (peso <= 0) {
        throw peso_invalido_e();
    }
}

void ProdutoAlimenticio::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    
    if (_vegano) {
        std::cout << "Produto vegano!" << std::endl;
    }
    std::cout << "Peso: " << _peso << "g" << std::endl;
    std::cout << "Data de validade: " << _dataDeValidade << std::endl;
    std::cout << "----------------------------" << std::endl;
}

bool ProdutoAlimenticio::get_vegano() const {
    return _vegano;
}

double ProdutoAlimenticio::get_peso() const {
    return _peso;
}

std::string ProdutoAlimenticio::get_data_validade() const {
    return _dataDeValidade;
}