#include <stdexcept>

#include "../include/mercado.hpp"

std::vector<std::string> Mercado::getTodasCategorias() {
    std::vector<std::string> categorias;

    for (Corredor *corredor : _corredores) {
        categorias.push_back(corredor->getCategoria());
    }
    return (categorias);
}

Corredor *Mercado::getCorredor(std::string categoria) {
    for (Corredor *corredor : _corredores) {
        if (corredor->getCategoria() == categoria) {
            return corredor;
        }
    }
    throw(std::invalid_argument("Corredor nao Encontrado!"));
}

Produto *Mercado::getProduto(std::string nome) {
    for (Corredor *corredor : _corredores) {
        for (Produto *produto : corredor->getTodosProdutos()) {
            if (produto->getNome() == nome) return produto;
        }
    }
    throw(std::invalid_argument("Produto nao Encontrado!"));
}

void Mercado::adicionarCorredor(Corredor *corredor) {
    _corredores.push_back(corredor);
}

std::vector<Corredor *> Mercado::getCorredores() {
    return _corredores;
}

void Mercado::adicionarNovoProduto(std::string categoria, Produto *produto) {
    for (auto &corredor : _corredores) {
        if (corredor->getCategoria() == categoria) {
            corredor->adicionarNovoProduto(produto);
            break;
        }
    }
}

void Mercado::adicionarProdutoJaExistente(std::string categoria, std::string nome_produto, unsigned int qtd) {
    for (auto &corredor : _corredores) {
        if (corredor->getCategoria() == categoria) {
            corredor->adicionarProdutoJaExistente(nome_produto, qtd);
            break;
        }
    }
}

void Mercado::removerCorredor(std::string categoria){
    bool corredorExiste = 0;
    for (auto it = _corredores.begin(); it != _corredores.end(); ++it){
        auto it2 = (*it);
        if (it2->getCategoria() == categoria){
            if (it2->getTodosProdutos().size() != 0) throw std::invalid_argument\
            ("O corredor deve estar vazio para ser removido! Por favor, remova todos os seus produtos antes.");
            _corredores.erase(it);
            corredorExiste = 1;
            break;
        }
    }
    if (corredorExiste == 0) throw std::invalid_argument("Corredor Inexistente!");
}