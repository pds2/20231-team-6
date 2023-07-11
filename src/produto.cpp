#include <iomanip>
#include <iostream>

#include "../include/produto.hpp"

Produto::Produto(const std::string &nome, double preco, unsigned int quantidade)
    : _nome(nome), _precoBase(preco), _quantidade(quantidade){
    if (quantidade <= 0){
        throw quantidade_invalida_e();
    }

    if (preco <= 0){
        throw preco_invalido_e();
    }
}

Produto::~Produto(){}

void Produto::imprimirInformacoes() {
    std::cout << "----------------------------" << std::endl;
    std::cout << "Nome: " << _nome << std::endl;
    //std::cout << "ID: " << _id << std::endl;
    std::cout << "Preço: R$" << std::fixed << std::setprecision(2) << _precoBase << std::endl;
    std::cout << "Quantidade em estoque: " << _quantidade << std::endl;
}

void Produto::removerEstoque(unsigned int valor){
  _quantidade -= valor;
}

std::string Produto::getNome() const {
    return _nome;
}

unsigned int Produto::getQuantidade() const {
    return _quantidade;
}

double Produto::getPreco() const {
    return _precoBase;
}

void Produto::adicionarEstoque(unsigned int qtd_adicionada){
    _quantidade = _quantidade + qtd_adicionada;
}

Produto* Produto::criarProdutoGenerico(std::string nome){
    double preco = preencherDouble("Preço");
    unsigned int quantidade = preencherInt("Quantidade a ser adicionada no estoque");
    Produto* novoProduto = new Produto(nome, preco, quantidade);
    return novoProduto;
}

std::vector <std::string> const Produto::_tipos_de_produto = {"Produto Genérico", "Produto Alimentício",
                                                              "Produto de Limpeza", "Produto Infantil", "Voltar"};

std::string Produto::confirmarComposicao(){
    imprimirInformacoes();

    std::cout << std::endl;
    std::string opcoes = mostrarOpcoesA("Deseja Confirmar A Adição do Novo Produto?", {"Sim", "Refazer","Cancelar"}, 1);
    return opcoes;
}