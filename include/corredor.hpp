#ifndef CORREDOR_HPP
#define CORREDOR_HPP

#include <vector>

#include "produto.hpp"
#include "produto_alimenticio.hpp"
#include "produto_infantil.hpp"
#include "produto_limpeza.hpp"

class Corredor {
  private:
    std::vector<Produto *> _produtos;
    std::string _categoria;

  public:
    Corredor(std::string categoria);
    ~Corredor();
    void adicionarNovoProduto(Produto *produto);
    void removerProduto(std::string nome);

    void adicionarProdutoJaExistente(std::string produto, unsigned int qtd);

    std::string getCategoria();
    std::vector<std::string> getNomeProdutos();
    Produto *getProduto(std::string nome);
    std::vector<Produto *> getTodosProdutos();
};

#endif // CORREDOR_HPP