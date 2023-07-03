#ifndef PRODUTO_INFANTIL_HPP
#define PRODUTO_INFANTIL_HPP

#include "produto.hpp"
#include <string>

struct idade_invalida_e {};

class ProdutoInfantil : public Produto {
  private:
    std::string _genero;
    unsigned int _idadeRecomendada;

  public:
    // Construtor
    ProdutoInfantil(const std::string &nome, double preco, int quantidade,
                     const std::string &genero, unsigned int idade);

    /*
     * Imprime as informações do produto infantil através da função imprimir_informacoes.
     * Além disso, imprime o genero do produto e a idade recomendada.
     */
    void imprimir_informacoes() override;
    std::string get_genero() const;
    unsigned int get_idade() const;
};

#endif // PRODUTO_INFANTIL_HPP