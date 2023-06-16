#ifndef PRODUTO_LIMPEZA_HPP
#define PRODUTO_LIMPEZA_HPP

#include "produto.hpp"
#include <string>

class ProdutoLimpeza : public Produto {
  private:
    std::string _aroma;

  public:
    ProdutoLimpeza(const std::string &nome, double preco, int quantidade, const std::string &aroma);
    void imprimir_informacoes() override;
    std::string getAroma() const;
};

#endif // PRODUTO_LIMPEZA_HPP