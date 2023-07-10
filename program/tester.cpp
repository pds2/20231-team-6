#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/sistema.hpp"

TEST_CASE("01 - Testando Os Construtores da Classe Produtos") {
    Produto testeGenerico("generico", 15, 2);
    CHECK(testeGenerico.getNome == "generico");
    CHECK(testeGenerico.getPreco == 15);
    CHECK(testeGenerico.getQuantidade == 2);
    ProdutoAlimenticio testeAlimenticio("alimenticio", 100, 10, 0, "30/08/2023");
    CHECK(testeAlimenticio.getNome == "alimenticio");
    CHECK(testeAlimenticio.getPreco == 100);
    CHECK(testeAlimenticio.getQuantidade == 10);
    CHECK(testeAlimenticio.getVegano == 0);
    CHECK(testeAlimenticio.getDataValidade == "30/08/2023");
    //...
}

TEST_CASE("02 - Testando Os Construtores da Classe Conta") {

}

