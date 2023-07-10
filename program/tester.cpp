#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/sistema.hpp"

TEST_CASE("01 - Testando O Construtor da Classe Produto") {
    Produto testeGenerico("generico", 15, 2);
    CHECK(testeGenerico.getNome() == "generico");
    CHECK(testeGenerico.getPreco() == 15);
    CHECK(testeGenerico.getQuantidade() == 2);
}

TEST_CASE("02 - Testando O Construtor da Classe ProdutoAlimenticio") {
    ProdutoAlimenticio testeAlimenticio("alimenticio", 100, 10, 0, 400, "30/08/2023");
    CHECK(testeAlimenticio.getNome() == "alimenticio");
    CHECK(testeAlimenticio.getPreco() == 100);
    CHECK(testeAlimenticio.getQuantidade() == 10);
    CHECK(testeAlimenticio.getVegano() == 0);
    CHECK(testeAlimenticio.getPeso() == 400);
    CHECK(testeAlimenticio.getDataValidade() == "30/08/2023");
}

TEST_CASE("03 - Testando O Construtor da Classe ProdutoLimpeza") {
    ProdutoLimpeza testeLimpeza("limpeza", 23, 4, "lavanda", 500);
    CHECK(testeLimpeza.getNome() == "limpeza");
    CHECK(testeLimpeza.getPreco() == 23);
    CHECK(testeLimpeza.getQuantidade() == 4);
    CHECK(testeLimpeza.getAroma() == "lavanda");
    CHECK(testeLimpeza.getVolume() == 500);
}

TEST_CASE("04 - Testando O Construtor da Classe ProdutoInfantil") {
    ProdutoInfantil testeInfantil("infantil", 23, 4, "Para todos", 10);
    CHECK(testeInfantil.getNome() == "limpeza");
    CHECK(testeInfantil.getPreco() == 23);
    CHECK(testeInfantil.getQuantidade() == 4);
    CHECK(testeInfantil.getGenero() == "Para todos");
    CHECK(testeInfantil.getIdade() == 10);
}

TEST_CASE("05 - Testando O Construtor da Classe Conta Admin (: Conta)") {
    Admin testeAdmin("usuario", "senha");
    CHECK(testeAdmin.getUsuario() == "usuario");
    CHECK(testeAdmin.verificarSenha("senha") == 1);
}

TEST_CASE("06 - Testando O Construtor da Classe Consumidor (: Conta)") {
    Consumidor testeConsumidor("usuario", "senha");
    CHECK(testeConsumidor.getUsuario() == "usuario");
    CHECK(testeConsumidor.verificarSenha("senha") == 1);
}

TEST_CASE("07 - Testando As Funcoes Relacionadas ao Saldo do Consumidor") {
    Consumidor testeConsumidor("usuario", "senha");
    testeConsumidor.adicionarSaldo(500);
    testeConsumidor.removerSaldo(200)
    CHECK(testeConsumidor.getSaldo() == (500-200));
}

TEST_CASE("08 - Testando As Funcoes Relacionadas ao Estoque de um Produto") {
    Produto testeGenerico("generico", 15, 500);
    testeGenerico.removerEstoque(120);
    testeGenerico.adicionarEstoque(30);
    CHECK(testeGenerico.getQuantidade() == (500-120+30));
}