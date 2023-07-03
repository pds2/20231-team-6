#include "../include/sistema.hpp"
#include <cctype>
#include <stdexcept>

Sistema::Sistema(){};// Carrega todas as informacoes DO banco de dados

void Sistema::paginaInicial(){
  while (true){
    limparTela();
    string opcao = mostrarOpcoes("\tPAGINA INICIAL", {"Fazer Login como Usuario", "Fazer Login como Administrador", "Cadastrar", "Fechar Programa"}, 1);

    if (opcao == "Fazer Login como Usuario"){
      paginaInicialLoginConsumidor();
    }
    
    if (opcao == "Fazer Login como Administrador"){
      paginaInicialLoginAdministrador();
    }

    if (opcao == "Cadastrar"){
      paginaInicialCadastroConsumidor();
    }

    if (opcao == "Fechar Programa"){
      // Chamar uma funcao para carregar todas as informacoes NO banco de dados
      std::cout << "Programa finalizado com sucesso. Obrigado!" << std::endl;
      break;
    }
  }
}

void Sistema::paginaInicialLoginConsumidor(){
  string opcao;
  do{
    limparTela();
    std::cout << "\tAREA DE LOGIN PARA USUARIOS" << std::endl;
    string usuario = preencherString("Usuario");
    string senha = preencherString("Senha");
    try{
      logarConsumidor(usuario, senha);
      opcao = "Voltar";
    }
    catch (invalid_argument &e){
      std::cout << e.what() << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
    }
  } while (opcao != "Voltar");  
}

void Sistema::paginaInicialLoginAdministrador(){
  string opcao;
  do{
    limparTela();
    std::cout << "\tAREA DE LOGIN PARA ADMINISTRADORES" << std::endl;
    string usuario = preencherString("Usuario");
    string senha = preencherString("Senha");
    try{
      logarAdminstrador(usuario, senha);
      opcao = "Voltar";
    }
    catch (invalid_argument &e){
      std::cout << e.what() << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
    }
  } while (opcao != "Voltar");  
}

void Sistema::paginaInicialCadastroConsumidor(){
  string opcao;
  do{
    limparTela();
    std::cout << "\tAREA DE CADASTRO PARA USUARIOS" << std::endl;
    string usuario = preencherString("Usuario");
    try{
      verificarUsuario(usuario);
      try{
        string senha = preencherString("Senha");
        string senha2 = preencherString("Digite a Senha Novamente");
        verificarSenhaCadastro(senha, senha2);
        
        std::cout << "Cadastro feito com sucesso! Bem vindo " << usuario << "!" << std::endl;
        sleep(2);
        Consumidor* u1 = new Consumidor(usuario, senha);
        _usuarios.push_back(u1);
        logarConsumidor(usuario, senha);
        opcao = "Voltar";
      }
      catch (invalid_argument &e){
        std::cout << e.what() << std::endl;
        opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
      }
    }
    catch (usuario_ja_existe_e &e){
      std::cout << "Usuario ja existe!" << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
    }
  } while(opcao != "Voltar");
}

void Sistema::paginaConsumidor(){
  while (true){
    limparTela();
    string opcao = mostrarOpcoes("\tUSUARIO LOGADO: ", {"Procurar Produto", "Listar Categorias", "Ver Carrinho", \
    "Ver Compras Passadas", "Trocar Senha", "Deslogar"}, 1);

    if (opcao == "Procurar Produto"){
      paginaConsumidorProcurarProduto();
    }

    if (opcao == "Listar Categorias"){
      paginaConsumidorListarCategorias();
    }

    if (opcao == "Ver Carrinho"){
      paginaConsumidorVerCarrinho();
    }

    if (opcao == "Ver Compras Passadas"){
      paginaConsumidorVerComprasPassadas();
    }

    if (opcao == "Trocar Senha"){
      paginaConsumidorTrocarSenha();
    }

    if (opcao == "Deslogar"){
      _consumidor_logado = nullptr;
      break;
    }
  }
}

void Sistema::paginaConsumidorProcurarProduto(){
  string opcao;
  do{
    limparTela();
    std::cout << "PAGINA PARA PROCURA DE PRODUTOS" << std::endl;
    string nomeproduto = preencherString("Digite o Nome do Produto que Deseja Procurar");
    nomeproduto = stringPesquisa(nomeproduto);
    try{
      detalhesProduto(nomeproduto);
      opcao = "Voltar";
    }
    catch(invalid_argument &e){
      std::cout << e.what() << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
    }
  } while (opcao != "Voltar");
}

void Sistema::paginaConsumidorListarCategorias(){
  string opcao;
  do{
    vector<string> categorias = _mercado.listarCategorias();
    categorias.push_back("Voltar");
    limparTela();
    opcao = mostrarOpcoes("ESCOLHA A CAREGORIA DESEJADA", categorias, 1);
    if (opcao != "Voltar"){
      paginaProdutosConsumidor(opcao);
    }
  } while (opcao != "Voltar");
}

void Sistema::paginaConsumidorVerCarrinho(){
  string opcao;
  do{
    limparTela();
    try {
      std::cout << "PRODUTOS NO CARRINHO" << std::endl;
      std::cout << "----------------------------" << std::endl;
      _consumidor_logado->exibirCarrinho();
    }
    catch (invalid_argument &e){
      std::cout << e.what() << std::endl;
      std::cout << "----------------------------" << std::endl;
      opcao = mostrarOpcoes("\n", {"Voltar"}, 0);
    }
    if (opcao != "Voltar"){
      std::cout << "----------------------------" << std::endl;
      opcao = mostrarOpcoes("\n", {"Finalizar Compra", "Remover Produto", "Voltar"}, 0);
      if (opcao == "Finalizar Compra"){
        paginaCheckout();
      }
      if (opcao == "Remover Produto"){
        paginaRemoverProduto();
      }
    }
  } while (opcao != "Voltar");
}

void Sistema::paginaConsumidorVerComprasPassadas(){
  string opcao;
  limparTela();
  std::cout << "COMPRAS PASSADAS" << std::endl;
  std::cout << "----------------------------" << std::endl;
  try{
    _consumidor_logado->exibirProdutosComprados();
  }
  catch (invalid_argument &e){
    std::cout << e.what() << std::endl;
  }
  std::cout << "----------------------------" << std::endl;
  opcao = mostrarOpcoes("\n", {"Voltar"}, 0);
}

void Sistema::paginaConsumidorTrocarSenha(){
  string opcao;
  do{
    limparTela();
    string senhaAtual = preencherString("Digite Sua Senha Atual");
    if (_consumidor_logado->verificarSenha(senhaAtual)){
      try{
        string novaSenha1 = preencherString("Nova Senha");
        string novaSenha2 = preencherString("Digite a Senha Novamente");
        verificarSenhaCadastro(novaSenha1, novaSenha2);
        _consumidor_logado->trocarSenha(novaSenha1);
        std::cout << "Senha Alterada Com Sucesso!" << std::endl;
        sleep (2);
        opcao = "Voltar";
      }
      catch(invalid_argument &e){
        std::cout << e.what() << std::endl;
        opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"},0);
      }
    }
    else{
      std::cout << "Senha Invalida!" << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
    }
  } while (opcao != "Voltar");
}

void Sistema::paginaProdutosConsumidor(string categoria){
  Corredor* c = _mercado.getCorredor(categoria);
  vector<string> produtos = c->getNomeProdutos();
  produtos.push_back("Voltar");
  string opcao;
  do{
    limparTela();
    opcao = mostrarOpcoes("ESCOLHA O PRODUTO DESEJADO", produtos, 1);
    if (opcao != "Voltar"){
      detalhesProduto(opcao);
    }
  }while(opcao != "Voltar");
}

void Sistema::detalhesProduto(string nome){
  Produto* escolha = _mercado.getProduto(nome);
  limparTela();
  escolha->imprimir_informacoes();
  string opcao = mostrarOpcoes("\n", {"Adicionar ao Carrinho", "Voltar"}, 0);
  while (opcao != "Voltar"){
    std::cout << "Digite a Quantidade que Deseja Comprar: ";
    unsigned int quantidade;
    while(!(std::cin>> quantidade)){
      std::cout<<"Quantidade Invalida! Por Favor Tente Novamente: ";
      std::cin.clear();
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (quantidade > escolha->get_quantidade()){
      std::cout << "Nao ha Estoque Suficiente!" << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
    }
    else {
      _consumidor_logado->adicionaProdutoCarrinho(escolha, quantidade);
      std::cout << "Produto Adicionado ao Carrinho com Sucesso!" << std::endl;
      sleep(2);
      break;
    }
  }
}

// Criar uma pagina para o checkout
void Sistema::paginaCheckout(){
  while(true){
    std::cout << "Tem Certeza que Deseja Finalizar a Compra (Sim/Nao): ";
    string confirmacao;
    std::cin >> confirmacao;
    for (auto &letra : confirmacao) letra = toupper(letra);
    if (confirmacao == "SIM"){
      if (_consumidor_logado->getSaldo() < _consumidor_logado->getPrecoTotalCarrinho()){
        std::cout << "Saldo Insuficiente!" << std::endl;
        sleep(2);
        break;
      }
      else {
        std::cout << "Compra Finalizada Com Sucesso! Obrigado." << std::endl;
        sleep(2);
        _consumidor_logado->removerSaldo(_consumidor_logado->getPrecoTotalCarrinho());
        _consumidor_logado->limparCarrinho();
        break;
      }
    }
    if (confirmacao == "NAO"){
      sleep(1);
      break;
    }
    std::cout << "Escolha Invalida!" << std::endl;
    sleep(1);
  }
}

void Sistema::paginaRemoverProduto(){
  string opcao;
  do{
    string produtoRemovido = preencherString("Digite Qual Produto Deseja Remover");
    produtoRemovido = stringPesquisa(produtoRemovido);
    unsigned int quantidade;
    std::cout << "Quantos Voce Deseja Remover: ";
    try{
      if(!(std::cin >> quantidade)) throw (quantidade_invalida_e());
      _consumidor_logado->removerProdutoCarrinho(_mercado.getProduto(produtoRemovido), quantidade);
      std::cout << "Produto Removido Com Sucesso!" << std::endl;
      sleep(2);
      break;
    }
    catch (invalid_argument &e){
      std::cout << e.what() << std::endl;
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
      if (opcao == "Voltar") break;
    }
    catch (quantidade_invalida_e &e){
      std::cout << "Quantidade Invalida! Por Favor Tente Novamente!" << std::endl;
      std::cin.clear();
      std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
      opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
      if (opcao == "Voltar") break;
    }
  }while (opcao != "Voltar");
}

// Cirar um ambiente para administradores
void Sistema::paginaAdmin(){
  limparTela();
  string opcao = mostrarOpcoes("\tADMINISTRADOR LOGADO: ", {"Editar Produtos", "Edtiar Corredores", "Editar Usuarios", "Criar Conta Admin", "Deslogar"}, 1);
  while (opcao != "Deslogar"){

  }
  _admin_logado = nullptr;
}

string Sistema::preencherString(string campo){
  std::cout << campo << ": ";
  string entrada;
  getline(std::cin, entrada);
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

void Sistema::adicionarMercado(Mercado m){
  _mercado = m;
}

string Sistema::mostrarOpcoes(string titulo, vector<string> opcoes, bool limpar){
  unsigned int escolha;
  bool flag = true;

  while (flag){
    if (titulo == "\tUSUARIO LOGADO: ") {
      std::cout << titulo << _consumidor_logado->getUsuario();
      std::cout << "\t\tSaldo: R$" << _consumidor_logado->getSaldo() << std::endl;
    }
    else if (titulo == "\tADMINISTRADOR LOGADO: ") std::cout << titulo << _admin_logado->getUsuario() << std::endl; 
    else if (titulo != "\n") std::cout << titulo << std::endl;

    for (unsigned int i = 0; i < opcoes.size(); i++){
    std::cout << i+1 << ". " << opcoes[i] << std::endl;
    }

    std::cin >> escolha;
    try{
      if (escolha > opcoes.size() || escolha == 0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
        throw invalid_argument("Escolha invalida!");
      }
      flag = false;
    }
    catch (invalid_argument &e){
      std::cout << e.what() << std::endl;
      sleep(1);
      if (limpar){
        limparTela();
      }
    }
  }
  std::cin.ignore(1000, '\n');
  return opcoes[escolha-1];
}

void Sistema::adicionarConsumidor(Consumidor* c){
  _usuarios.push_back(c);
}

std::string Sistema::escolherTipo(){
    limparTela();
    string opcao = mostrarOpcoes("\tESCOLHA O TIPO DO PRODUTO", _tipos_de_produto, 1);
      if(opcao != "Voltar"){
        return opcao;
      }
}

std::string Sistema::escolherCorredor(){
    limparTela();
    std::string voltar = "Voltar";
    vector<std::string> corredores;
    for(auto corredor : _mercado.getCorredores()){
      corredores.push_back(corredor->getCategoria());
    }
    corredores.push_back(voltar);
    
    string opcao = mostrarOpcoes("\tESCOLHA A CATEGORIA DO PRODUTO", corredores, 1);
      if(opcao != voltar){
      return opcao;
    }
}

void Sistema::adicionarProduto(){
    std::string categoria = escolherCorredor();
    //imprimir os produtos presentes no corredor em questao
    string opcao = mostrarOpcoes("\tDESEJA ADICIONAR UM NOVO PRODUTO AO ESTOQUE OU ADICIONAR À UM JA EXISTENTE?", {"Novo", "Ja Existente", "Voltar"}, 1);
    if(opcao == "Novo"){
      Produto* produtoNovo;
      _mercado.adicionarNovoProduto(categoria, produtoNovo);
    }
    else if(opcao == "Ja Existente"){
      unsigned int quantidade;
      std::string produto = paginaProdutosAdmin(categoria);
      std::cout << "Qual a quantidade a ser adicionada?" << std::endl;
      std::cin >> quantidade;
      _mercado.adicionarProdutoJaExistente(categoria, produto, quantidade);

    }
    else{};
}

Produto* Sistema::criarProduto(){
  std::string tipo = escolherTipo();
  if(tipo != "Voltar"){
    std::string nome = preencherString("Nome");
    double preco;
    unsigned int quantidade;
    std::cout << "Preço: " << std::endl;
    std::cin >> preco;
    std::cout << "Quantidade a ser adicionada no estoque: " << std::endl;
    std::cin >> quantidade;
    if(tipo == "Produto Genérico"){
      Produto* novoProduto = new Produto(nome, preco, quantidade);
    }
    else if(tipo == "Produto Alimentício"){
      bool vegano;
      int peso;
      std::string data_de_validade;
      mostrarOpcoes("O produto é vegano?", {"Sim", "Não"}, 0);
      std::cout << "Peso: " << std::endl;
      std::cin >> peso;
      std::cout << "Data de Validade: " << std::endl;
      std::cin >> data_de_validade;
      ProdutoAlimenticio* novoProduto = new ProdutoAlimenticio(nome, preco, quantidade, vegano, peso);
    }
    else if(tipo == "Produto de Limpeza"){
      Produto* novoProduto = new Produto(nome, preco, quantidade);
    }
    else if(tipo == "Produto Infantil"){
      Produto* novoProduto = new Produto(nome, preco, quantidade);
    }
    return novoProduto;
  }
}

std::string Sistema::paginaProdutosAdmin(string categoria){
  Corredor* c = _mercado.getCorredor(categoria);
  vector<string> produtos = c->getNomeProdutos();
  produtos.push_back("Voltar");
  string opcao;
  limparTela();
  opcao = mostrarOpcoes("ESCOLHA O PRODUTO DESEJADO", produtos, 1);
  if (opcao != "Voltar"){
    return opcao;
  }
}