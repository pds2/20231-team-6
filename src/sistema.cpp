#include "../include/sistema.hpp"

Sistema::Sistema(){};

string Sistema::mostrarOpcoes(vector<string> opcoes)
{
  for (unsigned int i = 0; i < opcoes.size(); i++){
    cout << i+1 << ". " << opcoes[i] << endl;
  }

  unsigned int escolha;
  bool b = true;


  // Tratar excecoes
  //while (b){
    cin >> escolha;
  //b = false
  //}

  cin.ignore(1000, '\n');
  return opcoes[escolha-1];
}

void Sistema::paginaInicial()
{
  while (true){
    // Chamar uma funcao para carregar todas as informacoes DO banco de dados
    limparTela();
    string opcao = mostrarOpcoes({"Fazer Login como Usuario", "Fazer Login como Administrador", "Cadastrar", "Fechar Programa"});

    if (opcao == "Fazer Login como Usuario"){
      do{
        limparTela();
        cout << "\tAREA DE LOGIN PARA USUARIOS" << endl;
        string usuario = preencherString("Usuario");
        string senha = preencherString("Senha");
        try{
          logarUsuario(usuario, senha);
          opcao = "Voltar";
        }
        catch (erro_no_login_e &e){
          opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
        }
      } while (opcao != "Voltar");
    }

    if (opcao == "Fazer Login como Administrador"){
      do{
        limparTela();
        cout << "\tAREA DE LOGIN PARA ADMINISTRADORES" << endl;
        string senha = preencherString("Senha");
        if (verificaAdmin(senha) == true){
          // Chamar uma tela para administradores
        }
        else{
          cout << "Senha invalida!" << endl;
          opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
        }
      } while (opcao != "Voltar");
    }

    if (opcao == "Cadastrar"){
      do{
        limparTela();
        string usuario = preencherString("Usuario");
        try{
          verificarUsuario(usuario);
          try{
            string senha = preencherString("Senha");
            string senha2 = preencherString("Digite a Senha Novamente");
            verificarSenhaCadastro(senha, senha2);
            
            cout << "Cadastro feito com sucesso! Bem vindo " << usuario << "!" << endl;
            sleep(2);
            opcao = "Voltar";
            Conta* u1 = new Conta(usuario, senha);
            _usuarios.push_back(u1);
            logarUsuario(usuario, senha);
          }
          catch (senha_invalida_e &e){
            cout << "Essa senha e invalida!" << endl;
            opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
          }
          catch (senhas_diferentes_e &e){
            cout << "As senhas nao coincidem!" << endl;
            opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
          }
        }
        catch (usuario_ja_existe_e &e){
          cout << "Usuario ja existe!" << endl;
          opcao = mostrarOpcoes({"Tentar Novamente", "Voltar"});
        }
      } while(opcao != "Voltar");
    }
    if (opcao == "Fechar Programa"){
      // Chamar uma funcao para carregar todas as informacoes NO banco de dados
      cout << "Programa finalizado com sucesso. Obrigado!" << endl;
      break;
    }
  }
}

// Pronto
string Sistema::preencherString(string campo){
  cout << campo << ": ";
  string entrada;
  getline(cin, entrada);
  return entrada;
}

// Pronto
void Sistema::logarUsuario(const string& usuario, const string& senha){
  try{
    Conta* u1 = encontrarUsuario(usuario,senha);
    _usuario_logado = u1;
    // Chamar uma tela para usuarios ja logados
  }
  catch (usuario_invalido_e &e){
    cout << "Usuario nao encontrado!" << endl;
    throw erro_no_login_e();
  }
  catch (senha_incorreta_e &e){
    cout << "Senha invalida!" << endl;
    throw erro_no_login_e();
  }
}

// Pronto
Conta* Sistema::encontrarUsuario(const string& usuario, const string& senha){
  for (Conta* c: _usuarios){
    if (c->getUsuario() == usuario){
      if (c->verificarSenha(senha) == true){
        return c;
      }
      throw senha_incorreta_e();
    }
  }
  throw usuario_invalido_e();
}

bool Sistema::verificaAdmin(const string& senha){
  if (senha == "admin"){ // Podemos colocar uma senha no banco de dados tambem
    return true;
  }
  return false;
}

void Sistema::verificarUsuario(const string& usuario){
  for (Conta* c: _usuarios){
    if (c->getUsuario() == usuario) throw usuario_ja_existe_e();
  }
}

void Sistema::verificarSenhaCadastro(const string& senha, const string& senha_novamente){
  bool certa = (senha.find("12345") == string::npos) && (senha.find(" ") == string::npos) && \
  (senha.size() >= 5 && senha.size() <= 50);

  if (!certa) throw senha_invalida_e();
  if (senha != senha_novamente) throw senhas_diferentes_e();
}

// Pronto
void Sistema::limparTela(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
