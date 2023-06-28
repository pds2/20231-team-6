#ifndef PRODUTO_ALIMENTICIO_HPP
#define PRODUTO_ALIMENTICIO_HPP

#include "produto.hpp"
#include <string>

class ProdutoAlimenticio : public Produto {
  private:
    bool _vegano;
    double _peso; // em gramas
    std::string _dataDeValidade;

  public:
    
    // Construtor
    ProdutoAlimenticio(const std::string &nome, double preco, int quantidade, bool vegano,
                       double peso, const std::string &dataValidade);

    /*
     * Imprime as informações do produto alimentício através da função imprimir_informacoes.
     * Além disso, imprime se o produto é vegano, o peso e a data de validade.
     */
    void imprimir_informacoes() override;

    bool getVegano() const;
    
    double getPeso() const;
    
    std::string getDataValidade() const;
};

#endif // PRODUTO_ALIMENTICIO_HPP