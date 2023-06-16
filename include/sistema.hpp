#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "mercado.hpp"
#include "conta.hpp"
#include "admin.hpp"

#include <cstdlib>
#include <exception>

class senha_invalida_e{};
class usuario_invalido_e{};
class erro_no_login_e{};
class idade_invalida_e{};

class Sistema{
private:
  Mercado _mercado;
  vector<Conta*> _usuarios;
  Conta* _usuario_logado = nullptr;
  Admin* _admin_logado = nullptr;

public:
  // Sempre que o programa comecar a rodar, o mercado e os usuarios devem ser puxados
  // do banco de dados e inicializados no sistema
  Sistema();

  // Facilitadores
  void limparTela();
  string mostrarOpcoes(vector<string> opcoes);
  string preencherString(string campo);


  // Usuario
  Conta* encontrarUsuario(const string& usuario, const string& senha);
  void logarUsuario(const string& usuario, const string& senha);

  // Administrador
  bool verificarAdmin(const string& senha);

  // Paginas
  void paginaInicial();

};

#endif