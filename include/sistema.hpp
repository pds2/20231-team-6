#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <unistd.h>
#include <vector>
#include <iomanip>

#include "auxiliares.hpp"
#include "conta_admin.hpp"
#include "conta_consumidor.hpp"
#include "mercado.hpp"

class usuario_invalido_e {};
class usuario_ja_existe_e {};
class senha_incorreta_e {};
class voltar_e {};

// Classe Sistema. Armazena uma instancia da classe Mercado e um vector de usuarios.
// É responsável pela manipulacao de dados tanto pela parte do consumidor tanto quanto do admin.
class Sistema {
  private:
    Mercado _mercado;
    std::vector<Conta *> _usuarios;
    Consumidor *_consumidor_logado{nullptr};
    Admin *_admin_logado{nullptr};

  public:
    // Construtor do sistema.
    Sistema();

    // Apaga todas as informações do sistema.
    void apagarSistema();

    /*
     * @brief Printa na tela todas as opções disponíveis para escolha do usuário,
     * bem como um título para a página (opcional). Retorna a opção escolhida.
     * @throws Lança uma exceção caso o usuário escolha uma opção inválida.
     */
    std::string mostrarOpcoes(std::string titulo, std::vector<std::string> opcoes, bool limpar);

    // CONSUMIDOR

    /*
     * @brief Recebe um usuário e uma senha e retorna a conta correspondente, além da informação se a
     * conta é um consumidor ou um administrador.
     * @throws Lança uma exceção caso o usuário não exista ou caso a senha esteja incorreta.
     */
    std::pair<Conta *, bool> encontrarUsuario(const std::string &usuario, const std::string &senha);

    /*
     * @brief Recebe um usuário e uma senha e loga o consumidor no sistema.
     * @throws Lança uma exceção caso haja algum erro no login.
     */
    void logarConsumidor(const std::string &usuario, const std::string &senha);

    /*
     * @brief Verifica se um nome de usuário é valido.
     * @throws Lança uma exceção caso o nome de usuário já esteja sendo utilizado
     * ou caso o nome seja "admin".
     */
    void verificarUsuario(const std::string &senha);

    /*
     * @brief Verifica se uma senha é valida na hora do cadastro.
     * @throws Lança uma exceção caso a senha possua espaços, a sequência
     * "12345" em qualquer parte, menos de 5 caracteres ou mais de 50.
     * @throws Lança uma exceção caso a primeira senha digitada seja diferente da segunda.
     */
    void verificarSenhaCadastro(const std::string &senha, const std::string &senha_novamente);

    // ADMINISTRADOR

    /*
     * @brief Recebe um usuário e uma senha e loga o administrador no sistema.
     * @throws Lança uma exceção caso haja algum erro no login.
     */
    void logarAdminstrador(const std::string &usuario, const std::string &senha);

    // PAGINAS

    /*
     * @brief Corresponde ao ambiente da página inicial: permite o usuário escolher entre
     * fazer login (como usuário ou como administrador), fazer um cadastro no sistema
     * ou fechar o programa.
     */
    void paginaInicial();
    void paginaInicialLoginConsumidor();
    void paginaInicialLoginAdministrador();
    void paginaInicialCadastroConsumidor();

    /* @brief Corresponde ao ambiente da página do consumidor: permite ele a escolher entre
     * procurar um produto por nome, ver uma lista de todas as categorias de produtos, bem como
     * os produtos dentro de cada categoria. Além disso, pode ver seu carrinho (onde poderá finalizar
     * a compra ou editá-lo) ou ver suas compras passadas. Por fim, também há a opção de trocar a senha
     * da conta ou deslogar do sistema.
     */
    void paginaConsumidor();
    void paginaConsumidorProcurarProduto();
    void paginaConsumidorListarCategorias();
    void paginaConsumidorVerCarrinho();
    void paginaConsumidorVerComprasPassadas();
    void paginaConsumidorTrocarSenha();

    /*
     * @brief São subpáginas da área verCarrinho: a primeira corresponde a um ambiente para o usuário
     * finalizar a compra. A segunda é a área onde o usuário pode remover produtos que não deseja mais
     * de seu carrinho.
     * @throws Lança uma exceção caso o produto que o usuário deseja remover não esteja em seu carrinho
     * ou caso ele tente remover uma quantidade inválida.
     */
    void paginaCheckout();
    void paginaRemoverProdutoCarrinho();


    /*
     * @brief Corresponde ao ambiente da página do administrador: permite ele a escolher entre
     * editar produtos (onde pode reduzir o estoque ou excluir produtos), editar corredoreses (onde pode
     * excluir corredores vazios ou adicionar novos) ou editar usuários (onde pode excluir contas indesejadas 
     * ou alterar saldo de consumidores). Por fim, há também a opção de criar uma nova conta para algum 
     * administrador novo ou deslogar do sistema.
     */
    void paginaAdmin();
    void paginaAdminEditarProdutos();
    void paginaAdminEditarCorredores();
    void paginaAdminCriarConta();
    void paginaAdminEditarUsuarios();

    /*
     * @brief São subpáginas do Admin, utilizadas para auxiliar nas funções proporcionadas aos
     * administradores.
     */
    void adicionarCorredor();
    void removerCorredor();
    void removerConta();
    void alterarSaldo();
    void adicionarProduto();
    void removerProduto();
    void remocaoProdutoFinal(std::string produto, std::string categoria);
    std::string paginaProdutosAdmin(std::string opcao);

    // OUTROS

    /*
     * @brief Lista todos os produtos de uma determinada categoria. O usuário pode escolher
     * o produto que quiser e entrar na página detalhada dele.
     */
    void paginaProdutosConsumidor(std::string categoria);

    /*
     * @brief É a página de um determinado produto, onde é listado seu nome, preço, desconto atual,
     * quantidade em estoque, entre outros.
     */
    void detalhesProduto(std::string nome);

    // Adiciona uma nova conta ao sistema.
    void adicionarConta(Conta *c);
    
    // Adiciona um novo corredor ao mercado do sistema.
    void adicionarCorredor(Corredor *corredor);

    /*
     * @brief Retorna o consumidor com o nome desejado.
     * @throws Lança uma exceção caso o consumidor não exista.
     */
    Consumidor* getConsumidor(std::string nome);

    // Cria um novo produto.
    Produto *criarProduto();

    /*
     * @brief Retorna true se não houver nenhum outro produto com certo nome no sistema.
     * Caso haja, retorna falso.
     */
    bool produtoValido(std::string nome);

    /*
     * @brief Retorna true se não houver nenhum corredor com certa categoria no sistema.
     * Caso haja, retorna falso.
     */
    bool corredorValido(std::string categoria);
};

#endif // SISTEMA_HPP
