#ifndef PRODUTO_INFANTIL_HPP
#define PRODUTO_INFANTIL_HPP

#include <string>

#include "produto.hpp"

struct idade_invalida_e {};

// Classe Produto Infantil que é uma subclasse de produto.
// Representa um produto geralmente comercializado para crianças e tem mais atributos 
// que um produto comum como idade e genero recomendados.
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

    // Funcao static (independente de haver uma instancia da classe) que permite com que o usuario
    // (admin) crie um produto infantil entrando com as informacoes necessarias.
    static Produto* criarProdutoInfantil(std::string nome);
};

#endif // PRODUTO_INFANTIL_HPP