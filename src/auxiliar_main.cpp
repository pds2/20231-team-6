#include "../include/auxiliar_main.hpp"

void adicionar_corredor_alimentos(Sistema &sistema){
    Corredor *alimentos = new Corredor("Alimentos");

    Produto *pA1 = new ProdutoAlimenticio("Arroz", 30.0, 10, 1, 1000, "20/12/2023");
    Produto *pA2 = new ProdutoAlimenticio("Pacote De Feijao", 20.0, 10, 1, 500, "14/11/2023");
    Produto *pA3 = new ProdutoAlimenticio("Batata", 15.0, 5, 1, 300, "09/10/2023");
    Produto *pA4 = new ProdutoAlimenticio("Peito De Frango", 13.0, 5, 0, 150, "09/09/2023");
    Produto *pA5 = new ProdutoAlimenticio("Pernil", 16.0, 9, 0, 120, "24/09/2023");
    Produto *pA6 = new ProdutoAlimenticio("Pão", 8.90, 9, 1, 100, "24/09/2023");
    Produto *pA7 = new ProdutoAlimenticio("Ovo", 2.0, 100, 0, 20, "24/09/2023");
    Produto *pA8 = new ProdutoAlimenticio("Banana", 5.0, 9, 1, 40, "24/09/2023");

    alimentos->adicionarNovoProduto(pA1);
    alimentos->adicionarNovoProduto(pA2);
    alimentos->adicionarNovoProduto(pA3);
    alimentos->adicionarNovoProduto(pA4);
    alimentos->adicionarNovoProduto(pA5);
    alimentos->adicionarNovoProduto(pA6);
    alimentos->adicionarNovoProduto(pA7);
    alimentos->adicionarNovoProduto(pA8);

    sistema.adicionarCorredor(alimentos);
}

void adicionar_corredor_vestimentas(Sistema &sistema){
    Corredor *vestimentas = new Corredor("Vestimentas");

    Produto *pV1 = new Produto("Sapato", 105.0, 2);
    Produto *pV2 = new Produto("Camisa", 70.0, 3);
    Produto *pV3 = new Produto("Oculos", 30.0, 5);
    Produto *pV4 = new Produto("Short", 60.0, 3);

    vestimentas->adicionarNovoProduto(pV1);
    vestimentas->adicionarNovoProduto(pV2);
    vestimentas->adicionarNovoProduto(pV3);
    vestimentas->adicionarNovoProduto(pV4);

    sistema.adicionarCorredor(vestimentas);
}

void adicionar_corredor_limpeza(Sistema &sistema){
    Corredor *limpeza = new Corredor("Produtos de Limpeza e Higiene");

    Produto *pL1 = new Produto("Vassoura", 40.0, 10);
    Produto *pL2 = new ProdutoLimpeza("Sabonete Liquido", 22.0, 10, "Lavanda", 500);
    Produto *pL3 = new ProdutoLimpeza("Detergente", 20.0, 10, "Sem Cheiro", 400);
    Produto *pL4 = new Produto("Conjunto Escovas De Dente (3 unidades)", 15, 10);
    Produto *pL5 = new ProdutoLimpeza("Pasta De Dente", 9.90, 10, "Menta", 120);
    Produto *pL6 = new Produto("Fraldas P", 40.0, 10);
    Produto *pL7 = new Produto("Fraldas M", 45.0, 10);
    Produto *pL8 = new Produto("Fraldas G", 50.0, 10);

    limpeza->adicionarNovoProduto(pL1);
    limpeza->adicionarNovoProduto(pL2);
    limpeza->adicionarNovoProduto(pL3);
    limpeza->adicionarNovoProduto(pL4);
    limpeza->adicionarNovoProduto(pL5);
    limpeza->adicionarNovoProduto(pL6);
    limpeza->adicionarNovoProduto(pL7);
    limpeza->adicionarNovoProduto(pL8);

    sistema.adicionarCorredor(limpeza);
}

void adicionar_corredor_infantil(Sistema &sistema){
    Corredor *infantil = new Corredor("Produtos Infantis e Brinquedos");

    Produto *pI1 = new ProdutoInfantil("Pista Carrinho Hotwheels", 200.0, 10, "Para Todos", 8);
    Produto *pI2 = new ProdutoInfantil("Bola de Futebol", 150.0, 20, "Para Todos", 4);
    Produto *pI3 = new ProdutoInfantil("Boneca Barbie", 100.0, 10, "Para Todos", 8);
    Produto *pI4 = new ProdutoInfantil("Lego Star Wars", 1200.0, 10, "Para Todos", 10);

    infantil->adicionarNovoProduto(pI1);
    infantil->adicionarNovoProduto(pI2);
    infantil->adicionarNovoProduto(pI3);
    infantil->adicionarNovoProduto(pI4);

    sistema.adicionarCorredor(infantil);
}

void adicionar_consumidores(Sistema &sistema){
    Consumidor *arthur = new Consumidor("arthur", "diniz");
    Consumidor *yan = new Consumidor("yan", "aquino");
    Consumidor *caio = new Consumidor("caio", "santt");
    Consumidor *rod = new Consumidor("arthur", "rod");

    arthur->adicionarSaldo(150.0);
    
    caio->adicionarSaldo(10000.0);

    sistema.adicionarConta(arthur);
    sistema.adicionarConta(caio);
    sistema.adicionarConta(yan);
    sistema.adicionarConta(rod);
}

void adicionar_admins(Sistema &sistema){
    Admin *adm = new Admin("teste", "teste");
    Admin *conta = new Admin("adm", "adm123");

    sistema.adicionarConta(adm);
    sistema.adicionarConta(conta);
}

