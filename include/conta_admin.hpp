#ifndef CONTA_ADMIN_HPP
#define CONTA_ADMIN_HPP

#include <string>
#include <vector>

#include "conta.hpp"

class Admin : public Conta {
  public:
    // Construtor de uma conta específica para um admin.
    Admin(const std::string &usuario, const std::string &senha);

    //~Admin() override;

    // Adiciona um ou mais produto(s) ao sistema.
    void adicionarProdutos();

    // Remove um ou mais produto(s) do sistema.
    void removerProdutos();

    // Cria novo desconto em um produto.
    void addDescontoProduto();

    // Cria novo desconto em uma categoria/corredor de produtos.
    void addDescontoCategoria();
};

#endif // CONTA_ADMIN_HPP