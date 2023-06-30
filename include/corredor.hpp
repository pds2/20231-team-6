#ifndef CORREDOR_HPP
#define CORREDOR_HPP

#include "produto.hpp"
#include <vector>

class Corredor{
private:
  vector <Produto*> _produtos;
  string _categoria;

public:
  Corredor(string categoria);
  void adicionarProduto(Produto* p);

  string getCategoria();
  Produto* getProduto(string nome);
  vector<string> getNomeProdutos();
  vector<Produto*> getTodosProdutos();
};

#endif // CORREDOR_HPP