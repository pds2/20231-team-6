#ifndef PRODUTO_LIMPEZA_HPP
#define PRODUTO_LIMPEZA_HPP

#include <string>

#include "produto.hpp"

struct volume_invalido_e {};

// Classe Produto Limpeza que é uma subclasse de produto.
// Representa um produto de limpeza e tem mais atributos que um produto comum,
// como seu aroma e um volume em mls.
class ProdutoLimpeza : public Produto {
  private:
    std::string _aroma;
    unsigned int _volume; // em ml

  public:
    // Construtor
    ProdutoLimpeza(const std::string &nome, double preco, int quantidade,
                   const std::string &aroma, unsigned int volume);

    ~ProdutoLimpeza() override;

    /*
     * Imprime as informações do produto de limpeza através da função imprimir_informacoes.
     * Além disso, imprime o aroma do produto e o volume.
     */
    void imprimirInformacoes() override;
    
    std::string getAroma() const;
    unsigned int getVolume() const;

    // Funcao static (independente de haver uma instancia da classe) que permite com que o usuario
    // (admin) crie um produto de limpeza entrando com as informacoes necessarias.
    static Produto* criarProdutoLimpeza(std::string nome);
};

#endif // PRODUTO_LIMPEZA_HPP