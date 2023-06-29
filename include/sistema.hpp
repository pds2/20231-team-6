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
  string mostrarOpcoes(string titulo, vector<string> opcoes);

  /*
  * @brief Printa na tela o que o usuário deve preencher e retorna a informação preenchida.
  */
  string preencherString(string campo);

  string stringPesquisa(string entrada);


  // CONSUMIDOR

 /*
  * @brief Recebe um usuário e uma senha e retorna a conta correspondente, além da informação se a
  * conta é um consumidor ou um administrador.
  * @throws Lança uma exceção caso o usuário não exista ou caso a senha esteja incorreta.
  */
  pair<Conta*, bool> encontrarUsuario(const string& usuario, const string& senha);

 /*
  * @brief Recebe um usuário e uma senha e loga o consumidor no sistema.
  * @throws Lança uma exceção caso haja algum erro no login.
  */
  void logarConsumidor(const string& usuario, const string& senha);

 /*
  * @brief Verifica se um nome de usuário é valido.
  * @throws Lança uma exceção caso o nome de usuário já esteja sendo utilizado
  * ou caso o nome seja "admin".
  */
  void verificarUsuario(const string& senha);

 /*
  * @brief Verifica se uma senha é valida na hora do cadastro.
  * @throws Lança uma exceção caso a senha possua espaços, a sequência
  * "12345" em qualquer parte, menos de 5 caracteres ou mais de 50.
  * @throws Lança uma exceção caso a primeira senha digitada seja diferente da segunda.
  */
  void verificarSenhaCadastro(const string& senha, const string& senha_novamente);

  // ADMINISTRADOR

 /*
  * @brief Recebe um usuário e uma senha e loga o administrador no sistema.
  * @throws Lança uma exceção caso haja algum erro no login.
  */
  void logarAdminstrador(const string& usuario, const string& senha);

  // PAGINAS

 /*
  * @brief Corresponde ao ambiente da página inicial: permite o usuário escolher entre
  * fazer login (como usuário ou como administrador), fazer um cadastro no sistema
  * ou fechar o programa.
  */
  void paginaInicial();
  void paginaCheckout();

  // Nao sei onde vai ficar
  void paginaProdutos(string opcao);
  void detalhesProduto(string nome);

  // Documentar após implementação
  void paginaAdmin();
  void paginaConsumidor();

};

#endif // SISTEMA_HPP
