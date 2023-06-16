#include "../include/produto.hpp"

#include <iostream>

int Produto::_proximoId = 0;

Produto::Produto(const std::string &nome, int quantidade, int preco)
    : _id(_proximoId++), _nome(nome), _quantidade(quantidade), _preco(preco) {
}

/*
 * Imprime as informações do produto.
 * Se o produto tiver desconto, imprime o preço anterior e o preço com desconto.
 */
void Produto::imprimir_informacoes() {
    std::cout << "\nNome: " << _nome << std::endl;
    std::cout << "ID: " << _id << std::endl;

    if (_desconto > 0) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "Produto com desconto de: " << _desconto << "%" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "Preço anterior: R$" << _preco << std::endl;
        std::cout << "Preço com desconto: R$" << _preco * (1 - _desconto / 100) << std::endl;
    } else {
        std::cout << "Preço: R$" << _preco << std::endl;
    }
    std::cout << "Quantidade em estoque: " << _quantidade << std::endl;
}

void Produto::aplicar_desconto(double desconto) {
    _desconto = desconto;
}

int Produto::get_id() {
    return _id;
}

std::string Produto::get_nome() {
    return _nome;
}

double Produto::get_desconto() {
    return _desconto;
}

double Produto::get_preco() {
    return _preco;
}

int Produto::get_quantidade() {
    return _quantidade;
}