#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "conta.hpp"

#include <string>
#include <vector>

using namespace std;

/*
    @brief Definição da classe admin (derivada de Conta) e seus métodos.
 */
class Admin : public Conta {
public:
    //Construtor de uma conta específica para um admin.
    Admin(const std::string& usuario, const std::string& senha);

    //~Admin() override;

    //Adiciona um ou mais produto(s) ao sistema.
    void adicionarProdutos();

    //Remove um ou mais produto(s) do sistema.
    void removerProdutos();

    //Cria novo desconto em um produto.
    void addDescontoProduto();
    
    //Cria novo desconto em uma categoria/corredor de produtos.
    void addDescontoCategoria();

};

#endif
