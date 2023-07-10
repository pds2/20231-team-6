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
    std::set<std::string> _produtosComprados;
    std::map<Produto *, unsigned int> _carrinho;
    double _saldo{0};

  public:
    // Construtor de uma conta específica para um consumidor.
    Consumidor(const std::string &usuario, const std::string &senha);

    ~Consumidor() override;

    void adicionaProdutoCarrinho(Produto *produto, unsigned int quantidade);
    void removerProdutoCarrinho(Produto *produto, unsigned int quantidade);
    void exibirCarrinho();
    void limparCarrinho();
    double getPrecoTotalCarrinho() const;

    void adicionarSaldo(double valor);
    void removerSaldo(double valor);
    double getSaldo() const;

    void adicionarProdutoComprado(const std::string &produto);
    void exibirProdutosComprados() const;
};

#endif // CONTA_CONSUMIDOR_HPP