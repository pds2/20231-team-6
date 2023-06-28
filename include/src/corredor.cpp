#include "../include/corredor.hpp"

string Corredor::getCategoria(){
  return _categoria;
}

vector<string> Corredor::getNomeProdutos(){
  vector<string> produtos;
  for (Produto* c : _produtos){
    produtos.push_back(c->get_nome());
  }
  return produtos;
}

Produto* Corredor::getProduto(string nome){
  Produto* escolha;
  for (Produto* p : _produtos){
    if (p->get_nome() == nome){
      escolha = p;
      break;
    }
  }
  return escolha;
}

vector<Produto*> Corredor::getTodosProdutos(){
  return _produtos;
}