#ifndef MERCADO_HPP
#define MERCADO_HPP

#include "corredor.hpp"

// Classe Mercado que armazena vários corredores de produtos da classe Corredor.
class Mercado {
  private:
    std::vector<Corredor *> _corredores;

  public:
    Mercado() = default;
    
    // Adiciona um novo corredor/categoria (pointer) ao mercado.
    void adicionarCorredor(Corredor *c);
    // Remove um corredor/categoria do mercado a partir de seu nome.
    void removerCorredor(std::string categoria);

    // Funcoes para adicionar produtos ao mercado.

    void adicionarNovoProduto(std::string categoria, Produto *produto);
    void adicionarProdutoJaExistente(std::string categoria, std::string nome_produto, unsigned int qtd);
    

    Produto *getProduto(std::string nome);
    std::vector<std::string> getTodasCategorias();
    Corredor *getCorredor(std::string tipo);
    std::vector<Corredor *> getCorredores();
};

#endif // MERCADO_HPP