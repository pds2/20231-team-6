#include "../include/corredor.hpp"
#include <stdexcept>

Corredor::Corredor(std::string categoria) {
    _categoria = categoria;
}

Corredor::~Corredor(){
    for (Produto* c : _produtos){
        delete c;
    }
}

void Corredor::adicionarNovoProduto(Produto *produto) {
    _produtos.push_back(produto);
}

void Corredor::adicionarProdutoJaExistente(std::string nome_produto, unsigned int qtd) {
    for (auto produto : _produtos) {
        if (produto->getNome() == nome_produto) {
            produto->adicionarEstoque(qtd);
            break;
        }
    }
}

std::string Corredor::getCategoria() {
    return _categoria;
}

std::vector<std::string> Corredor::getNomeProdutos() {
    std::vector<std::string> produtos;
    for (Produto *c : _produtos) {
        produtos.push_back(c->getNome());
    }
    return produtos;
}

Produto *Corredor::getProduto(std::string nome) {
    for (Produto *produto : _produtos) {
        if (produto->getNome() == nome) {
            return produto;
            break;
        }
    }
    throw(std::invalid_argument("Produto nao Encontrado!"));
}

std::vector<Produto *> Corredor::getTodosProdutos() {
    return _produtos;
}

void Corredor::removerProduto(std::string nome){
    bool produtoExiste = 0;
    for (auto it = _produtos.begin(); it != _produtos.end(); it++){
        auto it2 = (*it);
        if(it2->getNome() == nome){
            _produtos.erase(it);
            delete it2;
            produtoExiste = 1;
            break;
        }
    }
    if (produtoExiste == 0) throw std::invalid_argument("Produto Inexistente!");
}