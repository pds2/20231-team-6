#ifndef PRODUTO_ALIMENTICIO_HPP
#define PRODUTO_ALIMENTICIO_HPP

#include "produto.hpp"
#include <string>

struct peso_invalido_e {};

class ProdutoAlimenticio : public Produto {
  private:
    bool _vegano;
    int _peso; // em gramas
    std::string _dataDeValidade;

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

    static Produto* criarProdutoAlimenticio(std::string nome);
};

#endif // PRODUTO_ALIMENTICIO_HPP