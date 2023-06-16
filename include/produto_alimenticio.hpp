#ifndef PRODUTO_ALIMENTICIO_HPP
#define PRODUTO_ALIMENTICIO_HPP

#include "produto.hpp"
#include <string>

class ProdutoAlimenticio : public Produto {
  private:
    std::string _dataDeValidade;

  public:
    ProdutoAlimenticio(const std::string &nome, double preco, int quantidade, const std::string &dataValidade);
    void imprimir_informacoes() override;
    std::string getDataValidade() const;
};

#endif // PRODUTO_ALIMENTICIO_HPP