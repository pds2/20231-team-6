#include "../include/produto_alimenticio.hpp"

#include <iostream>

ProdutoAlimenticio::ProdutoAlimenticio(const std::string &nome, double preco, int quantidade, const std::string &dataDeValidade)
    : Produto(nome, preco, quantidade), _dataDeValidade(dataDeValidade) {
}

/*
 * Imprime as informações do produto alimentício através da função imprimir_informacoes.
 * Além disso, imprime a data de validade do produto.
 */
void ProdutoAlimenticio::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    std::cout << "Data de validade: " << _dataDeValidade << std::endl;
}

std::string ProdutoAlimenticio::getDataValidade() const {
    return _dataDeValidade;
}

