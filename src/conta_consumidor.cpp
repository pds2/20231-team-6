#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "../include/conta_consumidor.hpp"


Consumidor::Consumidor(const std::string& usuario, const std::string& senha) : Conta(usuario, senha){}

//Consumidor::~Consumidor(){}

void Consumidor::adicionaProdutoCarrinho(Produto* p, unsigned int quantidade){
  if (_carrinho.count(p) > 0){
    unsigned int quantidadeNoCarrinho = _carrinho[p];
    if (quantidadeNoCarrinho + quantidade > p->get_quantidade()){
      quantidade = p->get_quantidade();
    }
    else {
      quantidade = quantidadeNoCarrinho + quantidade;
    }
    _carrinho[p] = quantidade;
  }
  else{
    pair<Produto*, unsigned int> compra = {p,quantidade};
    _carrinho.insert(compra);
  }
}

void Consumidor::exibirCarrinho(){
  if (_carrinho.size() == 0) throw invalid_argument("Carrinho Vazio!");
  for (auto it = _carrinho.begin(); it != _carrinho.end(); ++it){
    cout << "Produto: "<< it->first->get_nome() << endl;
    cout << "Quantidade: " << it->second << endl;
    double preco = it->first->get_preco() * it->second;
    cout << "Preco: R$" << preco << endl;
    cout << "----------------------------" << endl;
  }
  cout << "Seu Saldo: R$" << getSaldo() << endl;
  cout << "Preco Total: R$" << getPrecoTotalCarrinho() << endl;
}

void Consumidor::limparCarrinho(){
   for (auto it = _carrinho.begin();; ++it){
    if (it == _carrinho.end()) break;
    it->first->removerEstoque(it->second);
    _produtosComprados.insert(it->first->get_nome());
   }
   _carrinho.clear();
}

void Consumidor::removerProdutoCarrinho(Produto* p, unsigned int quantidade){
  auto it = _carrinho.find(p);
  if (it == _carrinho.end()) throw invalid_argument("Produto Nao Encontrado!");
  if (quantidade > it->second || quantidade <= 0) throw quantidade_invalida_e();
  if (quantidade == it->second) _carrinho.erase(it);
  else{
    it->second -= quantidade;
  } 
}

void Consumidor::exibirProdutosComprados() const{
  if (_produtosComprados.size() == 0) throw invalid_argument("Nao Ha Compras Passadas!");
  for (string produto : _produtosComprados){
    cout << "- " << produto << endl;
  }
}

double Consumidor::getSaldo() const{
  return _saldo;
}

void Consumidor::adicionarSaldo(double valor){
  _saldo += valor;
}

void Consumidor::removerSaldo(double valor){
  _saldo -= valor;
}

double Consumidor::getPrecoTotalCarrinho() const{
  double precoTotal = 0;
  for (auto it = _carrinho.begin(); it != _carrinho.end(); ++it){
    precoTotal += it->first->get_preco() * it->second;
  }
  return precoTotal;
}