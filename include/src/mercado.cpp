#include "../include/mercado.hpp"
#include <stdexcept>

vector<string> Mercado::listarCategorias(){
  vector<string> categorias;
  for (Corredor* c : _corredores){
    categorias.push_back(c->getCategoria());
  }
  return (categorias);
}

Corredor* Mercado::getCorredor(string categoria){
  Corredor* escolha;
  for (Corredor* c: _corredores){
    if (c->getCategoria() == categoria){
      escolha = c;
      break;
    }
  }
  return escolha;
}

Produto* Mercado::getProduto(string nome){
  for (Corredor* c : _corredores){
    for (Produto* p : c->getTodosProdutos()){
      if (p->get_nome() == nome) return p; 
    }
  }
  throw (invalid_argument("Produto nao Encontrado!"));
}