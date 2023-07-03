#include <iomanip>
#include <iostream>

#include "../include/produto.hpp"

unsigned int Produto::_proximoId = 0;

Produto::Produto(const std::string &nome, double preco, unsigned int quantidade)
    : _id(_proximoId++), _nome(nome), _precoBase(preco), _quantidade(quantidade),
      _precoComDesconto(preco), _desconto(0) {
    if (quantidade <= 0){
        throw quantidade_invalida_e();
    }

    if (preco <= 0){
        throw preco_invalido_e();
    }
}

void Produto::imprimir_informacoes() {
    std::cout << "----------------------------" << std::endl;
    std::cout << "Nome: " << _nome << std::endl;
    //std::cout << "ID: " << _id << std::endl;

    if (_desconto > 0) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "Produto com desconto de: " << _desconto << "%" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "Preço anterior: R$" << std::fixed << std::setprecision(2) <<_precoBase << std::endl;
        std::cout << "Preço com desconto: R$" << std::fixed << std::setprecision(2) << _precoComDesconto << std::endl;
    } else {
        std::cout << "Preço: R$" << std::fixed << std::setprecision(2) << _precoBase << std::endl;
    }
    std::cout << "Quantidade em estoque: " << _quantidade << std::endl;
}

void Produto::aplicar_desconto(double desconto) {
    if (desconto <= 0 || desconto > 100){
        throw desconto_invalido_e();
    }
    _desconto = desconto;
    _precoComDesconto = _precoBase * (1 - _desconto / 100);
}

void Produto::remover_desconto() {
    _desconto = 0;
    _precoComDesconto = _precoBase;
}

void Produto::remover_estoque(unsigned int valor){
  _quantidade -= valor;
}

int Produto::get_id() const {
    return _id;
}

std::string Produto::get_nome() const {
    return _nome;
}

unsigned int Produto::get_quantidade() const {
    return _quantidade;
}

double Produto::get_preco() const {
    return _precoBase;
}

double Produto::get_preco_com_desconto() const {
    return _precoComDesconto;
}

double Produto::get_desconto() const {
    return _desconto;
}

void Produto::adicionarEstoque(unsigned int qtd_adicionada){
    _quantidade = _quantidade + qtd_adicionada;
}

Produto* Produto::criarProdutoGenerico(){
    std::string nome = preencherString("Nome");
    double preco = preencherDouble("Preço");
    unsigned int quantidade = preencherInt("Quantidade a ser adicionada no estoque");
    Produto* novoProduto = new Produto(nome, preco, quantidade);
    return novoProduto;
}

std::vector <std::string> const Produto::_tipos_de_produto = {"Produto Genérico", "Produto Alimentício", "Produto de Limpeza", \
"Produto Infantil", "Voltar"};

std::string Produto::confirmarComposicao(){
    imprimir_informacoes();
    std::cout << std::endl;
    std::string opcoes = mostrarOpcoesA("Deseja Confirmar A Adição do Novo Produto?", {"Sim", "Refazer","Cancelar"}, 1);
    return opcoes;
}