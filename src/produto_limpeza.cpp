#include "../include/produto_limpeza.hpp"

#include <iostream>

ProdutoLimpeza::ProdutoLimpeza(const std::string &nome, double preco, int quantidade,
                               const std::string &aroma, unsigned int volume)
    : Produto(nome, preco, quantidade), _aroma(aroma), _volume(volume) {
}

void ProdutoLimpeza::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    std::cout << "Aroma: " << _aroma << std::endl;
    std::cout << "Volume: " << _volume << " ml" << std::endl;
}

std::string ProdutoLimpeza::getAroma() const {
    return _aroma;
}

unsigned int ProdutoLimpeza::getVolume() const {
    return _volume;
}