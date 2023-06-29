#include "../include/sistema.hpp"
#include <cctype>
#include <stdexcept>

Sistema::Sistema(){};// Carrega todas as informacoes DO banco de dados

string Sistema::mostrarOpcoes(string titulo, vector<string> opcoes){
  unsigned int escolha;
  bool flag = true;

  while (flag){
    if (titulo == "\tUSUARIO LOGADO: ") cout << titulo << _consumidor_logado->getUsuario() << endl;
    else if (titulo == "\tADMINISTRADOR LOGADO: ") cout << titulo << _admin_logado->getUsuario() << endl; 
    else if (titulo != "\n") cout << titulo << endl;

    for (unsigned int i = 0; i < opcoes.size(); i++){
    cout << i+1 << ". " << opcoes[i] << endl;
    }

    cin >> escolha;
    try{
      if (escolha > opcoes.size() || escolha == 0){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
        throw invalid_argument("Escolha invalida!");
      }
      flag = false;
    }
    catch (invalid_argument &e){
      cout << e.what() << endl;
      sleep(1);
      if (opcoes[0] != "Adicionar ao Carrinho"){
        limparTela();
      }
    }
  }
  cin.ignore(1000, '\n');
  return opcoes[escolha-1];
}

void Sistema::paginaInicial(){
  while (true){
    limparTela();
    string opcao = mostrarOpcoes("\tPAGINA INICIAL", {"Fazer Login como Usuario", "Fazer Login como Administrador", "Cadastrar", "Fechar Programa"});

    if (opcao == "Fazer Login como Usuario"){
      do{
        limparTela();
        cout << "\tAREA DE LOGIN PARA USUARIOS" << endl;
        string usuario = preencherString("Usuario");
        string senha = preencherString("Senha");
        try{
          logarConsumidor(usuario, senha);
          opcao = "Voltar";
        }
        catch (invalid_argument &e){
          cout << e.what() << endl;
          opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"});
        }
      } while (opcao != "Voltar");
    }

    if (opcao == "Fazer Login como Administrador"){
      do{
        limparTela();
        cout << "\tAREA DE LOGIN PARA ADMINISTRADORES" << endl;
        string usuario = preencherString("Usuario");
        string senha = preencherString("Senha");
        try{
          logarAdminstrador(usuario, senha);
          opcao = "Voltar";
        }
        catch (invalid_argument &e){
          cout << e.what() << endl;
          opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"});
        }
      } while (opcao != "Voltar");
    }

    if (opcao == "Cadastrar"){
      do{
        limparTela();
        cout << "\tAREA DE CADASTRO PARA USUARIOS" << endl;
        string usuario = preencherString("Usuario");
        try{
          verificarUsuario(usuario);
          try{
            string senha = preencherString("Senha");
            string senha2 = preencherString("Digite a Senha Novamente");
            verificarSenhaCadastro(senha, senha2);
            
            cout << "Cadastro feito com sucesso! Bem vindo " << usuario << "!" << endl;
            sleep(2);
            Consumidor* u1 = new Consumidor(usuario, senha);
            _usuarios.push_back(u1);
            logarConsumidor(usuario, senha);
            opcao = "Voltar";
          }
          catch (invalid_argument &e){
            cout << e.what() << endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"});
          }
        }
        catch (usuario_ja_existe_e &e){
          cout << "Usuario ja existe!" << endl;
          opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"});
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

// Criar um ambiente pos login
void Sistema::paginaConsumidor(){
  while (true){
    limparTela();
    string opcao = mostrarOpcoes("\tUSUARIO LOGADO: ", {"Procurar Produto", "Listar Categorias", "Ver Carrinho", \
    "Ver Compras Passadas", "Trocar Senha", "Deslogar"});
    if (opcao == "Procurar Produto"){
      do{
        limparTela();
        cout << "PAGINA PARA PROCURA DE PRODUTOS" << endl;
        string nomeproduto = preencherString("Digite o Nome do Produto que Deseja Procurar");
        nomeproduto = stringPesquisa(nomeproduto);
        try{
          detalhesProduto(nomeproduto);
          opcao = "Voltar";
        }
        catch(invalid_argument &e){
          cout << e.what() << endl;
          opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"});
        }
      } while (opcao != "Voltar");
    }
    if (opcao == "Listar Categorias"){
      do{
        vector<string> categorias = _mercado.listarCategorias();
        categorias.push_back("Voltar");
        limparTela();
        opcao = mostrarOpcoes("ESCOLHA A CAREGORIA DESEJADA", categorias);
        if (opcao != "Voltar"){
          paginaProdutos(opcao);
        }
      } while (opcao != "Voltar");
    }
    if (opcao == "Ver Carrinho"){
      do{
        limparTela();
        try {
          _consumidor_logado->exibirCarrinho();
        }
        catch (invalid_argument &e){
          cout << e.what() << endl;
        }
        cout << "----------------------------" << endl;
        opcao = mostrarOpcoes("\n", {"Finalizar Compra", "Remover Produto", "Voltar"});
        if (opcao == "Finalizar Compra"){
          paginaCheckout();
        }
        if (opcao == "Remover Produto"){
          // Opcao de remover um produto do carrinho
        }
      }while (opcao != "Voltar");
    }
    if (opcao == "Deslogar"){
      _consumidor_logado = nullptr;
      break;
    }
  }
}

void Sistema::paginaProdutos(string categoria){
  Corredor* c = _mercado.getCorredor(categoria);
  vector<string> produtos = c->getNomeProdutos();
  produtos.push_back("Voltar");
  string opcao;
  do{
    limparTela();
    opcao = mostrarOpcoes("ESCOLHA O PRODUTO DESEJADO", produtos);
    if (opcao != "Voltar"){
      detalhesProduto(opcao);
    }
  }while(opcao != "Voltar");
}

void Sistema::detalhesProduto(string nome){
  Produto* escolha = _mercado.getProduto(nome);
  limparTela();
  escolha->imprimir_informacoes();
  string opcao = mostrarOpcoes("\n", {"Adicionar ao Carrinho", "Voltar"});
  while (opcao != "Voltar"){
    cout << "Digite a Quantidade que Deseja Comprar: ";
    unsigned int quantidade;
    while(!(cin>> quantidade)){
      cout<<"Quantidade Invalida! Por Favor Tente Novamente: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (quantidade > escolha->get_quantidade()){
      cout << "Nao ha Estoque Suficiente!" << endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"});
    }
    else {
      _consumidor_logado->adicionaProdutoCarrinho(escolha, quantidade);
      cout << "Produto Adicionado ao Carrinho com Sucesso!" << endl;
      sleep(2);
      break;
    }
  }
}

void Sistema::paginaCheckout(){

}

// Cirar um ambiente para administradores
void Sistema::paginaAdmin(){
  limparTela();
  string opcao = mostrarOpcoes("\tADMINISTRADOR LOGADO: ", {"Editar Produtos", "Edtiar Corredores", "Editar Usuarios", "Criar Conta Admin", "Deslogar"});
  while (opcao != "Deslogar"){

  }
  _admin_logado = nullptr;
}

string Sistema::preencherString(string campo){
  cout << campo << ": ";
  string entrada;
  getline(cin, entrada);
  return entrada;
}

string Sistema::stringPesquisa(string entrada){
  entrada[0] = toupper(entrada[0]);
  for (unsigned int i = 1 ; i < entrada.size(); i++){
    entrada[i] = tolower(entrada[i]);
    if (entrada[i] == ' '){
      entrada[i+1] = toupper(entrada[i+1]);
      i++;
    }
  }
  return entrada;
}

void Sistema::logarAdminstrador(const string& usuario, const string& senha){
  try{
    pair <Conta*, bool> pair = encontrarUsuario(usuario,senha);
    if (pair.second == 1) throw invalid_argument("Erro no login!");

    _admin_logado = dynamic_cast<Admin*>(pair.first);
    paginaAdmin();
  }
  catch (usuario_invalido_e &e){
    throw invalid_argument("Usuario nao encontrado!");
  }
  catch (senha_incorreta_e &e){
    throw invalid_argument("Senha invalida!");
  }
}

void Sistema::logarConsumidor(const string& usuario, const string& senha){
  try{
    pair <Conta*, bool> pair = encontrarUsuario(usuario,senha);
    if (pair.second == 0) throw invalid_argument("Erro no login!");

    _consumidor_logado = dynamic_cast<Consumidor*>(pair.first);
    paginaConsumidor();
  }
  catch (usuario_invalido_e &e){
    throw invalid_argument("Usuario nao encontrado!");
  }
  catch (senha_incorreta_e &e){
    throw invalid_argument("Senha invalida!");
  }
}

pair<Conta*, bool> Sistema::encontrarUsuario(const string& usuario, const string& senha){
  bool e_consumidor;
  for (Conta* c: _usuarios){
    if (c->getUsuario() == usuario){
      if (c->verificarSenha(senha) == true){
        try{
          Consumidor c1 = dynamic_cast<Consumidor&>((*c));
          e_consumidor = 1;
        }
        catch(bad_cast &e){
          e_consumidor = 0;
        }
        pair <Conta*,bool> retorno (c,e_consumidor);
        return retorno;
      }
      throw senha_incorreta_e();
    }
  }
  throw usuario_invalido_e();
}


void Sistema::verificarUsuario(const string& usuario){
  for (Conta* c: _usuarios){
    if (c->getUsuario() == usuario) throw usuario_ja_existe_e();
  }
}

void Sistema::verificarSenhaCadastro(const string& senha, const string& senha_novamente){
  bool certa = (senha.find("12345") == string::npos) && (senha.find(" ") == string::npos) && \
  (senha.size() >= 5 && senha.size() <= 50);

  if (!certa) throw invalid_argument("Senha invalida!");
  if (senha != senha_novamente) throw invalid_argument("As senhas nao coincidem!");
}

void Sistema::limparTela(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
