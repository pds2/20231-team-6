#ifndef CONSUMIDOR_HPP
#define CONSUMIDOR_HPP

#include "conta.hpp"
#include "produto.hpp"

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

/*
    @brief Definição da classe consumidor (derivada de Conta) e seus métodos.
 */
class Consumidor : public Conta {
private:
    
    std::set<std::string> _produtosComprados;
    map<Produto*, unsigned int> _carrinho;
    int _saldo;
    int _pontos;

public:
    //Construtor de uma conta específica para um consumidor.
    Consumidor(const std::string& usuario, const std::string& senha);

    //~Consumidor() override;
    
    void adicionarProdutoComprado(const std::string& produto);

    double getSaldo() const;

    void adicionarSaldo(double valor);
    void removerSaldo(double valor);

    double getPrecoTotalCarrinho() const;

    void exibirProdutosComprados() const;

    void adicionaProdutoCarrinho(Produto* p, unsigned int quantidade);
    void removerProdutoCarrinho(Produto* p, unsigned int quantidade);

    void exibirCarrinho();
    void limparCarrinho();
};

#endif
