#ifndef MERCADO_HPP
#define MERCADO_HPP

#include "corredor.hpp"
#include <iostream>


class Mercado{
private:
  vector<Corredor*> _corredores;

public:
  void adicionarCorredor (Corredor* c);

  vector<string> listarCategorias();
  Corredor* getCorredor(string tipo);
  Produto* getProduto(string nome);
};





#endif // MERCADO_HPP