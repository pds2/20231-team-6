#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../include/conta_consumidor.hpp"

Consumidor::Consumidor(const std::string &usuario, const std::string &senha)
    : Conta(usuario, senha) {
    adicionarSaldo(500);
}

Consumidor::~Consumidor(){}

void Consumidor::adicionaProdutoCarrinho(Produto *produto, unsigned int quantidade) {
    if (_carrinho.count(produto) > 0) {
        unsigned int quantidadeNoCarrinho = _carrinho[produto];

        if (quantidadeNoCarrinho + quantidade > produto->getQuantidade()) {
            quantidade = produto->getQuantidade();
        }
        else {
            quantidade += quantidadeNoCarrinho;
        }
        _carrinho[produto] = quantidade;
    }
    else {
        std::pair<Produto *, unsigned int> compra = {produto, quantidade};
        _carrinho.insert(compra);
    }
}

void Consumidor::removerProdutoCarrinho(Produto *produto, unsigned int quantidade) {
    auto it = _carrinho.find(produto);
    if (it == _carrinho.end()) throw std::invalid_argument("Produto Nao Encontrado!");
    if (quantidade > it->second || quantidade <= 0) throw quantidade_invalida_e();
    if (quantidade == it->second) _carrinho.erase(it);
    else {
        it->second -= quantidade;
    }
}

void Consumidor::exibirCarrinho() {
    if (_carrinho.size() == 0) throw std::invalid_argument("Carrinho Vazio!");

    for (auto it = _carrinho.begin(); it != _carrinho.end(); it++) {
        double preco = it->first->getPreco() * it->second;

        std::cout << "Produto: " << it->first->getNome() << std::endl;
        std::cout << "Quantidade: " << it->second << std::endl;
        std::cout << "Preco: R$" << std::fixed << std::setprecision(2) << preco << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
    std::cout << "Preco Total: R$" << std::fixed << std::setprecision(2) << getPrecoTotalCarrinho() << std::endl;
    std::cout << "Seu Saldo: R$" << std::fixed << std::setprecision(2) << getSaldo() << std::endl;
}

void Consumidor::limparCarrinho() {
    for (auto it = _carrinho.begin(); it != _carrinho.end(); it++) {
        it->first->removerEstoque(it->second);
        _produtosComprados.insert(it->first->getNome());
    }
    _carrinho.clear();
}

double Consumidor::getPrecoTotalCarrinho() const {
    double precoTotal = 0;

    for (auto it = _carrinho.begin(); it != _carrinho.end(); it++) {
        precoTotal += it->first->getPreco() * it->second;
    }
    return precoTotal;
}

void Consumidor::adicionarSaldo(double valor) {
    _saldo += valor;
}

void Consumidor::removerSaldo(double valor) {
    _saldo -= valor;
}

double Consumidor::getSaldo() const {
    return _saldo;
}

void Consumidor::exibirProdutosComprados() const {
    if (_produtosComprados.size() == 0) throw std::invalid_argument("Nao Ha Compras Passadas!");
    
    for (std::string produto : _produtosComprados) {
        std::cout << "- " << produto << std::endl;
    }
}