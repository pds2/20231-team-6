#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "../include/conta_admin.hpp"


Admin::Admin(const std::string& usuario, const std::string& senha) : Conta(usuario, senha){
// Fechar a conexão com o banco de dados
    sqlite3_close(db);
}

Admin::void adicionarProdutos(){

}


Admin::void removerProdutos(){

}


Admin::void addDescontoProduto(){

}
    

Admin::void addDescontoCategoria(){
    
}