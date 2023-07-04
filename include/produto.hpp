#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include "auxiliares.hpp"
#include <string>

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
    virtual void imprimir_informacoes();

    // Aplica um desconto ao produto alterando apenas preço com desconto.
    void aplicar_desconto(double desconto);

    // Seta _desconto para 0 e _precoComDesconto para _precoBase.
    void remover_desconto();
    void remover_estoque(unsigned int valor);
    int get_id() const;
    std::string get_nome() const;
    unsigned int get_quantidade() const;
    double get_preco() const;
    double get_preco_com_desconto() const;
    double get_desconto() const;

    void adicionarEstoque(unsigned int qtd_adicionada);

    static Produto* criarProdutoGenerico();

    static std::vector <std::string> const _tipos_de_produto;

    std::string confirmarComposicao();
};

#endif // PRODUTO_HPP