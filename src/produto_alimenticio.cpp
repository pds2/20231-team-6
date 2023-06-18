#include "../include/produto_alimenticio.hpp"

#include <iostream>

ProdutoAlimenticio::ProdutoAlimenticio(const std::string &nome, double preco, int quantidade, bool vegano, double peso,
                                       const std::string &dataDeValidade)
    : Produto(nome, preco, quantidade), _vegano(vegano), _peso(peso), _dataDeValidade(dataDeValidade) {
}


void ProdutoAlimenticio::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    if (_vegano) {
        std::cout << "Produto vegano!" << std::endl;
    }
    std::cout << "Peso: " << _peso << "g" << std::endl;
    std::cout << "Data de validade: " << _dataDeValidade << std::endl;
}

bool ProdutoAlimenticio::getVegano() const {
    return _vegano;
}

double ProdutoAlimenticio::getPeso() const {
    return _peso;
}

std::string ProdutoAlimenticio::getDataValidade() const {
    return _dataDeValidade;
}