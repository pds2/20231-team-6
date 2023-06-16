#include "../include/produto_limpeza.hpp"

#include <iostream>

ProdutoLimpeza::ProdutoLimpeza(const std::string &nome, double preco, int quantidade, const std::string &aroma)
    : Produto(nome, preco, quantidade), _aroma(aroma) {
}

/*
 * Imprime as informações do produto de limpeza através da função imprimir_informacoes.
 * Além disso, imprime o aroma do produto.
 */
void ProdutoLimpeza::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    std::cout << "Aroma: " << _aroma << std::endl;
}

std::string ProdutoLimpeza::getAroma() const {
    return _aroma;
}