#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "mercado.hpp"
#include "conta_admin.hpp"
#include "conta_consumidor.hpp"

#include <exception>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <limits>
#include <stdexcept>
#include <vector>
#include <typeinfo>

class usuario_invalido_e{};
class usuario_ja_existe_e{};
class senha_incorreta_e{};

class Sistema{
private:
  Mercado _mercado;
  vector <Conta*> _usuarios;
  Consumidor* _consumidor_logado = nullptr;
  Admin* _admin_logado = nullptr;

  //Vetor auxiliar com strings com o nome das subclasses.
  std::vector <std::string> _tipos_de_produto = {"Produto Genérico", "Produto Alimentício", "Produto de Limpeza", \
  "Produto Infantil", "Voltar"};

public:
 /*
  * Inicializa o sistema: puxa as todas as informações dos usuários e do
  * mercado, que estão armazenadas no banco de dados, e carrega localmente.
  */
  Sistema();

  // FACILITADORES

 /*
  * @brief Limpa a tela do console.
  */
  void limparTela();

 /*
  * @brief Printa na tela todas as opções disponíveis para escolha do usuário,
  * bem como um título para a página (opcional). Retorna a opção escolhida.
  * @throws Lança uma exceção caso o usuário escolha uma opção inválida.
  */
  std::string mostrarOpcoes(std::string titulo, std::vector<string> opcoes, bool limpar);

 /*
  * @brief Printa na tela o que o usuário deve preencher e retorna a informação preenchida.
  */
  std::string preencherString(std::string campo);

 /*
  * @brief Recebe uma string, que deve ser formatada de acordo com o padrão de pesquisa:
  * todas as palavras sempre começam com letra maiúscula.
  */
  std::string stringPesquisa(std::string entrada);


  // CONSUMIDOR

 /*
  * @brief Recebe um usuário e uma senha e retorna a conta correspondente, além da informação se a
  * conta é um consumidor ou um administrador.
  * @throws Lança uma exceção caso o usuário não exista ou caso a senha esteja incorreta.
  */
  pair<Conta*, bool> encontrarUsuario(const std::string& usuario, const std::string& senha);

 /*
  * @brief Recebe um usuário e uma senha e loga o consumidor no sistema.
  * @throws Lança uma exceção caso haja algum erro no login.
  */
  void logarConsumidor(const std::string& usuario, const std::string& senha);

 /*
  * @brief Verifica se um nome de usuário é valido.
  * @throws Lança uma exceção caso o nome de usuário já esteja sendo utilizado
  * ou caso o nome seja "admin".
  */
  void verificarUsuario(const std::string& senha);

 /*
  * @brief Verifica se uma senha é valida na hora do cadastro.
  * @throws Lança uma exceção caso a senha possua espaços, a sequência
  * "12345" em qualquer parte, menos de 5 caracteres ou mais de 50.
  * @throws Lança uma exceção caso a primeira senha digitada seja diferente da segunda.
  */
  void verificarSenhaCadastro(const std::string& senha, const std::string& senha_novamente);

  // ADMINISTRADOR

 /*
  * @brief Recebe um usuário e uma senha e loga o administrador no sistema.
  * @throws Lança uma exceção caso haja algum erro no login.
  */
  void logarAdminstrador(const std::string& usuario, const std::string& senha);

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
  * @throws Lança uma excessão caso o produto que o usuário deseja remover não esteja em seu carrinho
  * ou caso ele tente remover uma quantidade inválida.
  */
  void paginaCheckout();  
  void paginaRemoverProduto();


  void paginaAdmin();

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

  // Coloquei pra testar o main
  void adicionarConta(Conta* c);
  void adicionarMercado(Mercado m);

 /*
  * @brief Função que usa do método MostrarOpcoes para escolher se o produto a ser adicionado
  * será genérico ou de algum tipo específico (classe base -Produto- ou derivada).
  */
  std::string escolherTipo();

 /*
  * @brief Função que usa do método MostrarOpcoes para escolher a qual 
  * corredor o produto deverá ser adicionado.
  */
  std::string escolherCorredor();

 /*
  * @brief Funcao que adiciona o produto do tipo designado ao corredor designado no sistema.
  */  
  void adicionarProduto();

  Produto* criarProduto();

  std::string paginaProdutosAdmin(std::string opcao);
};

#endif // SISTEMA_HPP
