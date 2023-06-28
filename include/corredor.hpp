#ifndef CORREDOR_HPP
#define CORREDOR_HPP

#include "produto.hpp"
#include <vector>

class Corredor{
private:
  vector <Produto*> _produtos;
  string _categoria;

public:
  string getCategoria();
  Produto* getProduto(string nome);
  vector<string> getNomeProdutos();
  vector<Produto*> getTodosProdutos();
};

#endif // CORREDOR_HPP