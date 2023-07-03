#include "../include/produto_infantil.hpp"

#include <iostream>

ProdutoInfantil::ProdutoInfantil(const std::string &nome, double preco, int quantidade,
                                 const std::string &genero, unsigned int idade)
    : Produto(nome, preco, quantidade), _genero(genero), _idadeRecomendada(idade) {
    if (idade < 0){
        throw idade_invalida_e();
    }        
}

void ProdutoInfantil::imprimir_informacoes() {
    Produto::imprimir_informacoes();
    std::cout << "Genero: " << _genero << std::endl;
    std::cout << "Idade recomendada: " << _idadeRecomendada << std::endl;
    std::cout << "----------------------------" << std::endl;
}

std::string ProdutoInfantil::get_genero() const {
    return _genero;
}

unsigned int ProdutoInfantil::get_idade() const {
    return _idadeRecomendada;
}