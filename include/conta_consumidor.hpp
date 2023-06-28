#ifndef CONSUMIDOR_HPP
#define CONSUMIDOR_HPP

#include "conta.hpp"

#include <string>
#include <vector>
#include <map>

using namespace std;

/*
    @brief Definição da classe consumidor (derivada de Conta) e seus métodos.
 */
class Consumidor : public Conta {
private:
    
  std::vector<std::string> _produtosComprados;
  map<Produto*, int> _carrinho;
  int _saldo;
  int _pontos;

public:
  //Construtor de uma conta específica para um consumidor.
  Consumidor(const std::string& usuario, const std::string& senha);
  
  void adicionarProdutoComprado(const std::string& produto);

  void exibirProdutosComprados() const;

  void adicionaProdutoCarrinho(Produto* p, unsigned int quantidade);

  void exibirCarrinho();
};

#endif
