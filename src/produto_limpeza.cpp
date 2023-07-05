#include "../include/produto_limpeza.hpp"

#include <iostream>

ProdutoLimpeza::ProdutoLimpeza(const std::string &nome, double preco, int quantidade,
                               const std::string &aroma, unsigned int volume)
    : Produto(nome, preco, quantidade), _aroma(aroma), _volume(volume) {
    if (volume <= 0){
        throw volume_invalido_e();
    }
}

ProdutoLimpeza::~ProdutoLimpeza(){}

void ProdutoLimpeza::imprimirInformacoes() {
    Produto::imprimirInformacoes();
    std::cout << "Aroma: " << _aroma << std::endl;
    std::cout << "Volume: " << _volume << "ml" << std::endl;
    std::cout << "----------------------------" << std::endl;
}

std::string ProdutoLimpeza::getAroma() const {
    return _aroma;
}

unsigned int ProdutoLimpeza::getVolume() const {
    return _volume;
}

Produto* ProdutoLimpeza::criarProdutoLimpeza(){
    std::string nome = preencherString("Nome");
    nome = stringPesquisa(nome);
    double preco = preencherDouble("Preço");
    unsigned int quantidade = preencherInt("Quantidade a ser adicionada no estoque");
    std::string aroma = preencherString("Aroma");
    unsigned int volume = preencherInt("Volume");
    
    Produto* novoProduto = new ProdutoLimpeza(nome, preco, quantidade, aroma, volume);
    return novoProduto;
}