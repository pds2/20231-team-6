#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

#include "auxiliares.hpp"

struct quantidade_invalida_e {};
struct preco_invalido_e {};
struct desconto_invalido_e {};

// Classe produto que representa um produtod de um supermercado,
// seus atributos sao: nome, preço e a quantidade armazenada em estoque.
class Produto {
  private:
   
    std::string _nome;
    double _precoBase;
    unsigned int _quantidade;

  public:
    // Construtor.
    Produto(const std::string &nome, double preco, unsigned int quantidade);

    virtual ~Produto();

    /*
     * Imprime as informações do produto.
     * Se o produto tiver desconto, imprime o preço anterior e o preço com desconto.
     */
    virtual void imprimirInformacoes();

    // Remove uma quantidade dada de um produto existente.
    void removerEstoque(unsigned int valor);

    std::string getNome() const;
    unsigned int getQuantidade() const;
    double getPreco() const;

    // Adiciona uma quantidade dada de um produto existente.
    void adicionarEstoque(unsigned int qtd_adicionada);

    // Funcao static (independente de haver uma instancia da classe) que permite com que o usuario
    // (admin) crie um produto generico entrando com as informacoes necessarias.
    static Produto *criarProdutoGenerico(std::string nome);

    // Vetor auxiliar que guarda o nome das subclasses de Produto.
    static std::vector<std::string> const _tipos_de_produto;

    // Funcao que pede para o usuario (admin) confirmar a composicao de um
    // novo produto sendo criado. Imprime as informacoes e pede a confirmacao. 
    std::string confirmarComposicao();
};

#endif // PRODUTO_HPP