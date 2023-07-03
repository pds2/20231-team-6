#ifndef CORREDOR_HPP
#define CORREDOR_HPP

#include <vector>

#include "produto.hpp"
#include "produto_alimenticio.hpp"
#include "produto_infantil.hpp"
#include "produto_limpeza.hpp"

class Corredor{
private:
  std::vector <Produto*> _produtos;
  std::string _categoria;

public:
  Corredor(string categoria);
  void adicionarNovoProduto(Produto* p);
  void adicionarProdutoJaExistente(std::string produto, unsigned int qtd);

  std::string getCategoria();
  Produto* getProduto(std::string nome);
  std::vector<std::string> getNomeProdutos();
  std::vector<Produto*> getTodosProdutos();
};

#endif // CORREDOR_HPP