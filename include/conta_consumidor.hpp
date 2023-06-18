#ifndef CONSUMIDOR_HPP
#define CONSUMIDOR_HPP

#include "conta.hpp"

#include <string>
#include <vector>

using namespace std;

/*
    @brief Definição da classe consumidor (derivada de Conta) e seus métodos.
 */
class Consumidor : public Conta {
private:
    
    std::vector<std::string> produtosComprados;
    std::vector<std::string> carrinho;
    int saldo;
    int pontos;

public:
    //Construtor de uma conta específica para um consumidor.
    Consumidor(const std::string& usuario, const std::string& senha);
    
    void adicionarProdutoComprado(const std::string& produto);

    void exibirProdutosComprados() const;


};

#endif
