#include "../include/mercado.hpp"
#include <stdexcept>

std::vector<std::string> Mercado::listarCategorias(){
  std::vector<std::string> categorias;
  for (Corredor* c : _corredores){
    categorias.push_back(c->getCategoria());
  }
  return (categorias);
}

Corredor* Mercado::getCorredor(std::string categoria){
  Corredor* escolha;
  for (Corredor* c: _corredores){
    if (c->getCategoria() == categoria){
      escolha = c;
      break;
    }
  }
  return escolha;
}

Produto* Mercado::getProduto(std::string nome){
  for (Corredor* c : _corredores){
    for (Produto* p : c->getTodosProdutos()){
      if (p->get_nome() == nome) return p; 
    }
  }
  throw (std::invalid_argument("Produto nao Encontrado!"));
}

void Mercado::adicionarCorredor (Corredor* c){
  _corredores.push_back(c);
}

vector<Corredor*> Mercado::getCorredores(){
 return _corredores;
}

void Mercado::adicionarNovoProduto (std::string categoria, Produto* produto){
  for(auto& corredor : _corredores){
    if(corredor->getCategoria() == categoria){
      corredor->adicionarNovoProduto(produto);
      break;
    }
  }
}

void Mercado::adicionarProdutoJaExistente (std::string categoria, std::string nome_produto, unsigned int qtd){
  for(auto& corredor : _corredores){
    if(corredor->getCategoria() == categoria){
      corredor->adicionarProdutoJaExistente(nome_produto, qtd);
      break;
    }
  }
}