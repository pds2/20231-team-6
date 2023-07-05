#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

#include "auxiliares.hpp"

struct quantidade_invalida_e {};
struct preco_invalido_e {};
struct desconto_invalido_e {};

class Produto {
  private:
    static unsigned int _proximoId;

    unsigned int _id;
    std::string _nome;
    double _precoBase;
    unsigned int _quantidade;
    double _precoComDesconto;
    double _desconto;

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

    // Aplica um desconto ao produto alterando apenas preço com desconto.
    void aplicarDesconto(double desconto);

    // Seta _desconto para 0 e _precoComDesconto para _precoBase.
    void removerDesconto();
    void removerEstoque(unsigned int valor);
    int getId() const;
    std::string getNome() const;
    unsigned int getQuantidade() const;
    double getPreco() const;
    double getPrecoComDesconto() const;
    double getDesconto() const;

    void adicionarEstoque(unsigned int qtd_adicionada);

    static Produto *criarProdutoGenerico();

    static std::vector<std::string> const _tipos_de_produto;

    std::string confirmarComposicao();
};

#endif // PRODUTO_HPP