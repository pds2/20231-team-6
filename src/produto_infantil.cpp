#include "../include/produto_infantil.hpp"

#include <iostream>

ProdutoInfantil::ProdutoInfantil(const std::string &nome, double preco, int quantidade,
                                 const std::string &genero, unsigned int idade)
    : Produto(nome, preco, quantidade), _genero(genero), _idadeRecomendada(idade) {
    if (idade < 0){
        throw idade_invalida_e();
    }        
}

ProdutoInfantil::~ProdutoInfantil() {}

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

Produto* ProdutoInfantil::criarProdutoInfantil(){
    std::string nome = preencherString("Nome");
    nome = stringPesquisa(nome);
    double preco = preencherDouble("Preço");
    unsigned int quantidade = preencherInt("Quantidade a ser adicionada no estoque");
    std::string genero = preencherString("Genero");
    unsigned int idade = preencherInt("Idade Recomendada");
    Produto* novoProduto = new ProdutoInfantil(nome, preco, quantidade, genero, idade);
    return novoProduto;
}