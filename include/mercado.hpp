#ifndef MERCADO_HPP
#define MERCADO_HPP

#include "corredor.hpp"
#include <iostream>


class Mercado{
private:
  std::vector<Corredor*> _corredores;

public:
  void adicionarCorredor (Corredor* c);

  std::vector<std::string> listarCategorias();
  Corredor* getCorredor(std::string tipo);
  Produto* getProduto(std::string nome);
};





#endif // MERCADO_HPP