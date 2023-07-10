#ifndef CONTA_CONSUMIDOR_HPP
#define CONTA_CONSUMIDOR_HPP

#include <map>
#include <set>
#include <string>
#include <vector>

#include "conta.hpp"
#include "produto.hpp"

/*
    @brief Definição da classe consumidor (derivada de Conta) e seus métodos.
 */
class Consumidor : public Conta {
  private:
    // Set (entradas únicas) com os produtos comprados anteriormente.
    std::set<std::string> _produtosComprados;
    // Carrinho de compras.
    std::map<Produto *, unsigned int> _carrinho;
    // Saldo.
    double _saldo{0};

  public:
    // Construtor de uma conta específica para um consumidor.
    Consumidor(const std::string &usuario, const std::string &senha);

    ~Consumidor() override;

    // Funcao para adicionar uma quantidade de um produto ao carrinho do consumidor.
    void adicionaProdutoCarrinho(Produto *produto, unsigned int quantidade);
    // Funcao para remover uma quantidade de um produto ao carrinho do consumidor.
    void removerProdutoCarrinho(Produto *produto, unsigned int quantidade);

    // Funcao que exibe os produtos no carrinho, suas informacoes e o preco total da compra.
    void exibirCarrinho();

    // Funcao que esvazia o carrinho de compras.
    void limparCarrinho();

    double getPrecoTotalCarrinho() const;

    // Funcao que adiciona saldo para o consumidor. 
    void adicionarSaldo(double valor);
    // Funcao que remove saldo do consumidor.
    void removerSaldo(double valor);

    double getSaldo() const;

    // Funcao que lista (imprime) os produtos comprados anteriormente.
    void exibirProdutosComprados() const;
};

#endif // CONTA_CONSUMIDOR_HPP