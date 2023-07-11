#ifndef CORREDOR_HPP
#define CORREDOR_HPP

#include <vector>

#include "produto.hpp"
#include "produto_alimenticio.hpp"
#include "produto_infantil.hpp"
#include "produto_limpeza.hpp"

// Classe que armazena um corredor de Produtos de certa categoria em forma de vector,
// também apresenta uma string com o nome da categoria dos produtos no corredor.
class Corredor {
  private:
    std::vector<Produto *> _produtos;
    std::string _categoria;

  public:
    // Construtor que recebe o nome da categoria do corredor.
    Corredor(std::string categoria);
    ~Corredor();

    // Funcao que adiciona um novo produto (pointer) no corredor.
    void adicionarNovoProduto(Produto *produto);
    // Funcao que remove um produto do corredor a partir de seu nome.
    void removerProduto(std::string nome);
    // Funcao que adiciona ao estoque uma quantidade de um produto ja existente.
    void adicionarProdutoJaExistente(std::string produto, unsigned int qtd);

    std::string getCategoria();
    std::vector<std::string> getNomeProdutos();
    Produto *getProduto(std::string nome);
    std::vector<Produto *> getTodosProdutos();
};

#endif // CORREDOR_HPP