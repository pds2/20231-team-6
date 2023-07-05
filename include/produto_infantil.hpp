#ifndef PRODUTO_INFANTIL_HPP
#define PRODUTO_INFANTIL_HPP

#include <string>

#include "produto.hpp"

struct idade_invalida_e {};

class ProdutoInfantil : public Produto {
  private:
    std::string _genero;
    unsigned int _idadeRecomendada;

  public:
    // Construtor
    ProdutoInfantil(const std::string &nome, double preco, int quantidade,
                     const std::string &genero, unsigned int idade);

    ~ProdutoInfantil() override;
    
    /*
     * Imprime as informações do produto infantil através da função imprimir_informacoes.
     * Além disso, imprime o genero do produto e a idade recomendada.
     */
    void imprimirInformacoes() override;
    
    std::string getGenero() const;
    unsigned int getIdade() const;

    static Produto* criarProdutoInfantil();
};

#endif // PRODUTO_INFANTIL_HPP