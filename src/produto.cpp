#include "../include/produto.hpp"

#include <iostream>

unsigned int Produto::_proximoId = 0;

Produto::Produto(const std::string &nome, int quantidade, int preco)
    : _id(_proximoId++), _nome(nome), 
      _quantidade(quantidade), _precoBase(preco), 
      _precoComDesconto(preco), _desconto(0) {
}

void Produto::imprimir_informacoes() {
    std::cout << "\nNome: " << _nome << std::endl;
    std::cout << "ID: " << _id << std::endl;

    if (_desconto > 0) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "Produto com desconto de: " << _desconto << "%" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "Preço anterior: R$" << _precoBase << std::endl;
        std::cout << "Preço com desconto: R$" << _precoComDesconto << std::endl;
    } else {
        std::cout << "Preço: R$" << _precoBase << std::endl;
    }
    std::cout << "Quantidade em estoque: " << _quantidade << std::endl;
}

void Produto::aplicar_desconto(double desconto) {
    _desconto = desconto;
    _precoComDesconto = _precoBase * (1 - _desconto / 100);
}

void Produto::remover_desconto() {
    _desconto = 0;
    _precoComDesconto = _precoBase;
}

int Produto::get_id() const {
    return _id;
}

std::string Produto::get_nome() const {
    return _nome;
}

int Produto::get_quantidade() const {
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