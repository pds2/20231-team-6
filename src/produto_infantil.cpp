#include "../include/produto_infantil.hpp"

#include <iostream>

ProdutoInfantil::ProdutoInfantil(const std::string &nome, double preco, int quantidade,
                                 const std::string &genero, unsigned int idade)
    : Produto(nome, preco, quantidade), _genero(genero), _idadeRecomendada(idade) {
}

void ProdutoInfantil::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    std::cout << "Genero: " << _genero << std::endl;
    std::cout << "Idade recomendada: " << _idadeRecomendada << std::endl;
}

std::string ProdutoInfantil::getGenero() const {
    return _genero;
}

unsigned int ProdutoInfantil::getIdade() const {
    return _idadeRecomendada;
}