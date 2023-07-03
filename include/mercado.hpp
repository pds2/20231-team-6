#ifndef MERCADO_HPP
#define MERCADO_HPP

#include "corredor.hpp"
#include <iostream>


class Mercado{
private:
  std::vector<Corredor*> _corredores;

public:
  void adicionarCorredor (Corredor* c);

  void adicionarNovoProduto (std::string categoria, Produto* produto);
  void adicionarProdutoJaExistente (std::string categoria, std::string nome_produto, unsigned int qtd);

  vector<string> listarCategorias();
  Corredor* getCorredor(string tipo);
  Produto* getProduto(string nome);
  vector<Corredor*> getCorredores();
};





#endif // MERCADO_HPP