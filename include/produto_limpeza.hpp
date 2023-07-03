#ifndef PRODUTO_LIMPEZA_HPP
#define PRODUTO_LIMPEZA_HPP

#include "produto.hpp"
#include <string>

struct volume_invalido_e {};

class ProdutoLimpeza : public Produto {
  private:
    std::string _aroma;
    unsigned int _volume; // em ml

  public:
    // Construtor
    ProdutoLimpeza(const std::string &nome, double preco, int quantidade,
                   const std::string &aroma, unsigned int volume);

    /*
     * Imprime as informações do produto de limpeza através da função imprimir_informacoes.
     * Além disso, imprime o aroma do produto e o volume.
     */
    void imprimir_informacoes() override;
    std::string get_aroma() const;
    unsigned int get_volume() const;
};

#endif // PRODUTO_LIMPEZA_HPP