#ifndef MERCADO_HPP
#define MERCADO_HPP

#include "corredor.hpp"

class Mercado {
  private:
    std::vector<Corredor *> _corredores;

  public:
    Mercado() = default;
    
    void adicionarCorredor(Corredor *c);

    void adicionarNovoProduto(std::string categoria, Produto *produto);
    void adicionarProdutoJaExistente(std::string categoria, std::string nome_produto, unsigned int qtd);
    void removerCorredor(std::string categoria);

    Produto *getProduto(std::string nome);
    std::vector<std::string> getTodasCategorias();
    Corredor *getCorredor(std::string tipo);
    std::vector<Corredor *> getCorredores();
};

#endif // MERCADO_HPP