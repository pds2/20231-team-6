#include "../include/corredor.hpp"


std::string Corredor::getCategoria(){
  return _categoria;
}

std::vector<std::string> Corredor::getNomeProdutos(){
  std::vector<std::string> produtos;
  for (Produto* c : _produtos){
    produtos.push_back(c->get_nome());
  }
  return produtos;
}

Produto* Corredor::getProduto(std::string nome){
  Produto* escolha;
  for (Produto* p : _produtos){
    if (p->get_nome() == nome){
      escolha = p;
      break;
    }
  }
  return escolha;
}

std::vector<Produto*> Corredor::getTodosProdutos(){
  return _produtos;
}

void Corredor::adicionarProduto(Produto* p){
  _produtos.push_back(p);
}

Corredor::Corredor(std::string categoria){
  _categoria = categoria;
}