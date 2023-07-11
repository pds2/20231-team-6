#include <iostream>

#include "../include/produto_infantil.hpp"

ProdutoInfantil::ProdutoInfantil(const std::string &nome, double preco, int quantidade,
                                 const std::string &genero, unsigned int idade)
    : Produto(nome, preco, quantidade), _genero(genero), _idadeRecomendada(idade) {
    if (idade < 0){
        throw idade_invalida_e();
    }        
}

ProdutoInfantil::~ProdutoInfantil() {}

void ProdutoInfantil::imprimirInformacoes() {
    Produto::imprimirInformacoes();
    std::cout << "Genero: " << _genero << std::endl;
    std::cout << "Idade recomendada: " << _idadeRecomendada << std::endl;
}

std::string ProdutoInfantil::getGenero() const {
    return _genero;
}

unsigned int ProdutoInfantil::getIdade() const {
    return _idadeRecomendada;
}

Produto* ProdutoInfantil::criarProdutoInfantil(std::string nome){
    double preco = preencherDouble("Preço");
    unsigned int quantidade = preencherInt("Quantidade a ser adicionada no estoque");
    std::string genero = mostrarOpcoesA("O produto é recomendado para qual gênero?", \
                                        {"Masculino", "Feminino", "Ambos"}, 0);
    unsigned int idade = preencherInt("Idade Recomendada");
    Produto* novoProduto = new ProdutoInfantil(nome, preco, quantidade, genero, idade);
    return novoProduto;
}