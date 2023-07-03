#include "../include/sistema.hpp"

int main(){
  Sistema s;
  Mercado m;

  Corredor* vestimentas = new Corredor("Vestimentas");
  Corredor* alimentos = new Corredor("Alimentos");

  Produto* p1 = new Produto("Arroz", 30.0, 10);
  Produto* p2 = new Produto("Pacote De Feijao", 20.0, 10);
  Produto* p3 = new Produto("Batata", 15.0, 5);
  Produto* p4 = new Produto("Sapato", 105.0, 2);
  Produto* p5 = new Produto("Camisa", 70.0, 3);
  Produto* p6 = new Produto("Oculos", 30.0, 5);
  Produto* p7 = new Produto("Short", 60.0, 3);

  alimentos->adicionarProduto(p1);
  alimentos->adicionarProduto(p2);
  alimentos->adicionarProduto(p3);

  vestimentas->adicionarProduto(p4);
  vestimentas->adicionarProduto(p5);
  vestimentas->adicionarProduto(p6);
  vestimentas->adicionarProduto(p7);

  m.adicionarCorredor(vestimentas);
  m.adicionarCorredor(alimentos);

  Consumidor* Arthur = new Consumidor("Arthur", "diniz");
  Consumidor* Pedro = new Consumidor("Pedro", "diniz");

  s.adicionarConsumidor(Arthur);
  s.adicionarConsumidor(Pedro);

  Arthur->adicionarSaldo(150.0);

  s.adicionarMercado(m);
  s.paginaInicial();
  return 0;
}