#ifndef PRODUTO_ALIMENTICIO_HPP
#define PRODUTO_ALIMENTICIO_HPP

#include "produto.hpp"
#include <string>

struct peso_invalido_e {};

// Classe Produto Alimenticio que é uma subclasse de produto.
// Representa um alimento e tem mais atributos que um produto comum,
// como data de validade, preco e um verificador de que se o alimento é vegano ou não.
class ProdutoAlimenticio : public Produto {
  private:
    bool _vegano;
    int _peso; // em gramas
    std::string _dataDeValidade; // no formato DD/MM/YYYY

  public:
    
    // Construtor
    ProdutoAlimenticio(const std::string &nome, double preco, int quantidade, bool vegano,
                       int peso, const std::string &dataValidade);

    ~ProdutoAlimenticio();
    /*
     * Imprime as informações do produto alimentício através da função imprimir_informacoes.
     * Além disso, imprime se o produto é vegano, o peso e a data de validade.
     */
    void imprimirInformacoes() override;
    
    bool getVegano() const;
    double getPeso() const;
    std::string getDataValidade() const;

    // Funcao static (independente de haver uma instancia da classe) que permite com que o usuario
    // (admin) crie um produto alimenticio entrando com as informacoes necessarias.
    static Produto* criarProdutoAlimenticio(std::string nome);
};

#endif // PRODUTO_ALIMENTICIO_HPP