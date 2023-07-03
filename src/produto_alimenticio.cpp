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

Produto* ProdutoAlimenticio::criarProdutoAlimenticio(){
    std::string nome = preencherString("Nome");
    double preco = preencherDouble("Preço");
    unsigned int quantidade = preencherInt("Quantidade a ser adicionada no estoque");
    int peso = preencherInt("Peso");

    bool vegano;
    std::string é_vegano = mostrarOpcoesA("O produto é vegano?", {"Sim", "Não"}, 0);
    if(é_vegano == "Sim") vegano = true;
    else if(é_vegano == "Não") vegano = false;

    std::string data_de_validade = preencherString("Data de Validade");
    Produto* novoProduto = new ProdutoAlimenticio(nome, preco, quantidade, vegano, peso, data_de_validade);
    return novoProduto;
}