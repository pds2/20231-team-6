#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

#include "auxiliares.hpp"

struct quantidade_invalida_e {};
struct preco_invalido_e {};
struct desconto_invalido_e {};

class Produto {
  private:
   
    std::string _nome;
    double _precoBase;
    unsigned int _quantidade;

  public:
    /*
     * Construtor. Inicializa _precoComDesconto igual ao _precoBase
     * e o _desconto igual a 0
     */
    Produto(const std::string &nome, double preco, unsigned int quantidade);

    virtual ~Produto();

    /*
     * Imprime as informações do produto.
     * Se o produto tiver desconto, imprime o preço anterior e o preço com desconto.
     */
    virtual void imprimirInformacoes();

    // Seta _desconto para 0 e _precoComDesconto para _precoBase.
    void removerEstoque(unsigned int valor);
    std::string getNome() const;
    unsigned int getQuantidade() const;
    double getPreco() const;

    void adicionarEstoque(unsigned int qtd_adicionada);

    static Produto *criarProdutoGenerico(std::string nome);

    static std::vector<std::string> const _tipos_de_produto;

    std::string confirmarComposicao();
};

#endif // PRODUTO_HPP