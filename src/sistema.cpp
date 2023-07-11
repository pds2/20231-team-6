#include <cctype>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>

#include "../include/sistema.hpp"

Sistema::Sistema(){};

void Sistema::paginaInicial() {
    while (true) {
        limparTela();
        std::string opcao = mostrarOpcoes(
            "\tPAGINA INICIAL",
            {"Fazer Login como Usuario", "Fazer Login como Administrador", "Cadastrar", "Fechar Programa"}, 1);

        if (opcao == "Fazer Login como Usuario") {
            paginaInicialLoginConsumidor();
        }

        if (opcao == "Fazer Login como Administrador") {
            paginaInicialLoginAdministrador();
        }

        if (opcao == "Cadastrar") {
            paginaInicialCadastroConsumidor();
        }

        if (opcao == "Fechar Programa") {
            apagarSistema();
            std::cout << "Programa finalizado com sucesso. Obrigado!" << std::endl;
            break;
        }
    }
}

void Sistema::paginaInicialLoginConsumidor() {
    std::string opcao;
    
    do {
        limparTela();
        std::cout << "\tAREA DE LOGIN PARA USUARIOS" << std::endl;

        std::string usuario = preencherString("Usuario");
        std::string senha = preencherString("Senha");

        try {
            logarConsumidor(usuario, senha);
            opcao = "Voltar";
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaInicialLoginAdministrador() {
    std::string opcao;

    do {
        limparTela();
        std::cout << "\tAREA DE LOGIN PARA ADMINISTRADORES" << std::endl;

        std::string usuario = preencherString("Usuario");
        std::string senha = preencherString("Senha");

        try {
            logarAdminstrador(usuario, senha);
            opcao = "Voltar";
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaInicialCadastroConsumidor() {
    std::string opcao;

    do {
        limparTela();
        std::cout << "\tAREA DE CADASTRO PARA USUARIOS" << std::endl;

        std::string usuario = preencherString("Usuario");

        try {
            verificarUsuario(usuario);
            try {
                std::string senha = preencherString("Senha");
                std::string senha2 = preencherString("Digite a Senha Novamente");
                verificarSenhaCadastro(senha, senha2);
                std::cout << "Cadastro feito com sucesso! Bem vindo " << usuario << "!" << std::endl;
                
                sleep(1);
                Consumidor *u1 = new Consumidor(usuario, senha);
                _usuarios.push_back(u1);
                logarConsumidor(usuario, senha);

                opcao = "Voltar";
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
                opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
            }
        } catch (usuario_ja_existe_e &e) {
            std::cout << "Usuario ja existe!" << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaConsumidor() {
    while (true) {
        limparTela();
        std::string opcao = mostrarOpcoes("\tUSUARIO LOGADO: ",
                                          {"Procurar Produto", "Listar Categorias", "Ver Carrinho",
                                           "Ver Compras Passadas", "Trocar Senha", "Deslogar"},
                                          1);

        if (opcao == "Procurar Produto") {
            paginaConsumidorProcurarProduto();
        }

        if (opcao == "Listar Categorias") {
            paginaConsumidorListarCategorias();
        }

        if (opcao == "Ver Carrinho") {
            paginaConsumidorVerCarrinho();
        }

        if (opcao == "Ver Compras Passadas") {
            paginaConsumidorVerComprasPassadas();
        }

        if (opcao == "Trocar Senha") {
            paginaConsumidorTrocarSenha();
        }

        if (opcao == "Deslogar") {
            _consumidor_logado = nullptr;
            break;
        }
    }
}

void Sistema::paginaConsumidorProcurarProduto() {
    std::string opcao;

    do {
        limparTela();
        std::cout << "PAGINA PARA PROCURA DE PRODUTOS" << std::endl;

        std::string nomeproduto = preencherString("Digite o Nome do Produto que Deseja Procurar");
        nomeproduto = stringPesquisa(nomeproduto);
        try {
            detalhesProduto(nomeproduto);
            opcao = "Voltar";
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaConsumidorListarCategorias() {
    std::string opcao;

    do {
        std::vector<std::string> categorias = _mercado.getTodasCategorias();
        categorias.push_back("Voltar");

        limparTela();
        opcao = mostrarOpcoes("ESCOLHA A CAREGORIA DESEJADA", categorias, 1);

        if (opcao != "Voltar") {
            paginaProdutosConsumidor(opcao);
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaConsumidorVerCarrinho() {
    std::string opcao;

    do {
        limparTela();

        try {
            std::cout << "PRODUTOS NO CARRINHO" << std::endl;
            std::cout << "----------------------------" << std::endl;
            _consumidor_logado->exibirCarrinho();
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            std::cout << "----------------------------" << std::endl;
            opcao = mostrarOpcoes("\n", {"Voltar"}, 0);
        }
        if (opcao != "Voltar") {
            std::cout << "----------------------------" << std::endl;
            opcao = mostrarOpcoes("\n", {"Finalizar Compra", "Remover Produto", "Voltar"}, 0);

            if (opcao == "Finalizar Compra") {
                paginaCheckout();
            }
            if (opcao == "Remover Produto") {
                paginaRemoverProdutoCarrinho();
            }
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaConsumidorVerComprasPassadas() {
    std::string opcao;

    limparTela();
    std::cout << "COMPRAS PASSADAS" << std::endl;
    std::cout << "----------------------------" << std::endl;

    try {
        _consumidor_logado->exibirProdutosComprados();
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------------------------" << std::endl;
    opcao = mostrarOpcoes("\n", {"Voltar"}, 0);
}

void Sistema::paginaConsumidorTrocarSenha() {
    std::string opcao;

    do {
        limparTela();
        std::string senhaAtual = preencherString("Digite Sua Senha Atual");

        if (_consumidor_logado->verificarSenha(senhaAtual)) {
            try {
                std::string novaSenha1 = preencherString("Nova Senha");
                std::string novaSenha2 = preencherString("Digite a Senha Novamente");
                verificarSenhaCadastro(novaSenha1, novaSenha2);
                _consumidor_logado->trocarSenha(novaSenha1);

                std::cout << "Senha Alterada Com Sucesso!" << std::endl;
                sleep(2);
                opcao = "Voltar";
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
                opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
            }
        } else {
            std::cout << "Senha Invalida!" << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (opcao != "Voltar");
}

void Sistema::paginaProdutosConsumidor(std::string categoria) {
    Corredor *corredor = _mercado.getCorredor(categoria);
    std::vector<std::string> produtos = corredor->getNomeProdutos();
    std::string opcao;

    produtos.push_back("Voltar");

    do {
        limparTela();
        opcao = mostrarOpcoes("ESCOLHA O PRODUTO DESEJADO", produtos, 1);
        
        if (opcao != "Voltar") {
            detalhesProduto(opcao);
        }
    } while (opcao != "Voltar");
}

void Sistema::detalhesProduto(std::string nome) {
    Produto *escolha = _mercado.getProduto(nome);

    limparTela();
    escolha->imprimirInformacoes();
    std::cout << "----------------------------" << std::endl;
    std::string opcao = mostrarOpcoes("\n", {"Adicionar ao Carrinho", "Voltar"}, 0);

    while (opcao != "Voltar") {
        unsigned int quantidade;

        std::cout << "Digite a Quantidade que Deseja Comprar: ";
        while (!(std::cin >> quantidade)) {
            std::cout << "Quantidade Invalida! Por Favor Tente Novamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (quantidade > escolha->getQuantidade() || escolha->getQuantidade() == 0) {
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
void Sistema::paginaCheckout() {
    while (true) {
        std::cout << "Tem Certeza que Deseja Finalizar a Compra (Sim/Nao): ";
        std::string confirmacao;
        std::cin >> confirmacao;

        for (auto &letra : confirmacao)
            letra = toupper(letra);

        if (confirmacao == "SIM") {
            if (_consumidor_logado->getSaldo() < _consumidor_logado->getPrecoTotalCarrinho()) {
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
        else if (confirmacao == "NAO") {
            sleep(1);
            break;
        }
        std::cout << "Escolha Invalida!" << std::endl;
        sleep(1);
    }
}

void Sistema::paginaRemoverProdutoCarrinho() {
    std::string opcao;
    
    do {
        std::string produtoRemovido = preencherString("Digite Qual Produto Deseja Remover");
        produtoRemovido = stringPesquisa(produtoRemovido);
        
        unsigned int quantidade;
        std::cout << "Quantos Voce Deseja Remover: ";
        try {
            if (!(std::cin >> quantidade)) throw(quantidade_invalida_e());

            _consumidor_logado->removerProdutoCarrinho(_mercado.getProduto(produtoRemovido), quantidade);
            std::cout << "Produto Removido Com Sucesso!" << std::endl;
            sleep(2);
            break;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);

            if (opcao == "Voltar") break;
        } catch (quantidade_invalida_e &e) {
            std::cout << "Quantidade Invalida! Por Favor Tente Novamente!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
            if (opcao == "Voltar") break;
        }
    } while (opcao != "Voltar");
}

// Cirar um ambiente para administradores
void Sistema::paginaAdmin() {
    while (true) {
        limparTela();
        std::string opcao = mostrarOpcoes(
            "\tADMINISTRADOR LOGADO: ",
            {"Editar Produtos", "Editar Corredores", "Editar Usuarios", "Criar Conta Admin", "Deslogar"}, 1);

        if (opcao == "Editar Produtos") {
            paginaAdminEditarProdutos();
        }

        if (opcao == "Edtiar Corredores"){
            paginaAdminEditarCorredores();
        }

        if (opcao == "Editar Usuarios"){
            paginaAdminEditarUsuarios();
        }

        if (opcao == "Criar Conta Admin"){
            paginaAdminCriarConta();
        }

        if (opcao == "Deslogar") {
            _admin_logado = nullptr;
            break;
        }
    }
}

void Sistema::paginaAdminEditarProdutos(){
    limparTela();
    std::string opcao = mostrarOpcoes("\tSELECIONE O QUE DESEJA EDITAR NOS PRODUTOS", {"Adicionar", "Remover", "Voltar"} , 1);
    if (opcao == "Adicionar"){
        adicionarProduto();
    }
    if (opcao == "Remover"){
        removerProduto();
    }
}

void Sistema::paginaAdminEditarCorredores(){
    limparTela();
    std::string opcao = mostrarOpcoes("\tSELECIONE O QUE DESEJA EDITAR NOS CORREDORES", {"Adicionar", "Remover", "Voltar"} , 1);
    if (opcao == "Adicionar"){
        adicionarCorredor();
    }
    if (opcao == "Remover"){
        removerCorredor();
    }
}

void Sistema::paginaAdminEditarUsuarios(){
    limparTela();
    std::string opcao = mostrarOpcoes("\tSELECIONE O QUE DESEJA EDITAR NOS USUARIOS", {"Alterar Saldo", "Remover Conta", "Voltar"}, 1);
    if (opcao == "Remover Conta"){
        removerConta();
    }
    if (opcao == "Alterar Saldo"){
        alterarSaldo();
    }
}

void Sistema::removerConta(){
    std::vector<std::string> nomeContas;
    for (Conta* c : _usuarios){
        if (c->getUsuario() != _admin_logado->getUsuario()){
            nomeContas.push_back(c->getUsuario());
        }
    }
    nomeContas.push_back("Voltar");
    std::string conta;
    do{
        limparTela();
        conta = mostrarOpcoes("\tSELECIONE A CONTA QUE DESEJA REMOVER", nomeContas, 1);
        if (conta != "Voltar"){
            std::cout << "Tem certeza que deseja remover a conta " << conta << " do sistema?" << std::endl;
            std::string confirmacao = mostrarOpcoes("\n", {"Confirmar", "Voltar"}, 0);
            if (confirmacao == "Confirmar"){
                for (auto it = _usuarios.begin(); it != _usuarios.end(); ++it){
                    auto it2 = (*it);
                    if (it2->getUsuario() == conta){
                        _usuarios.erase(it);
                        delete it2;
                    }
                }
                std::cout << "A conta " << conta << " foi removida do sistema com sucesso!" << std::endl;
                sleep(1);
                conta = "Voltar";
            }
        }
    } while (conta != "Voltar");
}

void Sistema::alterarSaldo(){
    std::string escolha;
    do{
        limparTela();
        std::set<std::string> nomeConsumidores;
        std::cout << "\tLISTA DE CONSUMIDORES" << std::endl;
        std::cout << "----------------------------" << std::endl;
        for (Conta* c : _usuarios){
            try {
                Consumidor c1 = dynamic_cast<Consumidor &>(*c);
                nomeConsumidores.insert(c1.getUsuario());
                std::cout << "Usuario: " << c1.getUsuario() << std::endl;
                std::cout << "Saldo: R$ " << std::fixed << std::setprecision(2) << c1.getSaldo() << std::endl;
                std::cout << "----------------------------" << std::endl;

            } catch (std::bad_cast &e) {}
        }
        escolha = preencherString("Digite o nome do usuario que deseja alterar o saldo (fique atento a letras maiúsculas!)");
        if (nomeConsumidores.count(escolha) > 0){
            std::string alterarSaldoEscolha = mostrarOpcoes("\n", {"Adicionar", "Remover"}, 0);
            std::cout << "O usuario " << escolha << " tem saldo: R$ " << std::fixed << std::setprecision(2) << getConsumidor(escolha)->getSaldo() << std::endl;
            double alteracaoSaldo = preencherDouble("Digite a quantidade de saldo que deseja alterar ou 0 para cancelar");
            if (alterarSaldoEscolha == "Adicionar") getConsumidor(escolha)->adicionarSaldo(alteracaoSaldo);
            else{
                if (getConsumidor(escolha)->getSaldo() - alteracaoSaldo < 0) alteracaoSaldo = getConsumidor(escolha)->getSaldo();
                getConsumidor(escolha)->removerSaldo(alteracaoSaldo);
            }
            std::cout << "O saldo de " << escolha << " foi alterado com sucesso! Seu novo saldo é de: R$" \
            << std::fixed << std::setprecision(2) << getConsumidor(escolha)->getSaldo() << std::endl;
            sleep(1);     
        } 
        else {
            std::cout << "Usuario Invalido! Por favor, tente novamente." << std::endl;
            escolha = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (escolha == "Tentar Novamente");
}

Consumidor* Sistema::getConsumidor(std::string nome){
    Conta* padrao;
    for (Conta* c : _usuarios){
        if (c->getUsuario() == nome){
            padrao = c;
        }
    }
    try{
        Consumidor c1 = dynamic_cast<Consumidor &>((*padrao));
        Consumidor* retorno = dynamic_cast<Consumidor*>(padrao);
        return retorno;
    }
    catch(std::bad_cast &e){
        throw std::invalid_argument("Essa conta nao pertence a um usuario ou nao existe!");
    }
}

void Sistema::paginaAdminCriarConta(){
    std::string opcao;

    do {
        limparTela();
        std::cout << "\tAREA PARA CRIAR NOVOS ADMINISTADORES" << std::endl;
        std::string usuario = preencherString("Usuario");
        try {
            verificarUsuario(usuario);
            try {
                std::string senha = preencherString("Senha");
                std::string senha2 = preencherString("Digite a Senha Novamente");
                verificarSenhaCadastro(senha, senha2);
                std::cout << "O cadastro da conta " << usuario << " foi feito com sucesso!" << std::endl;
               
                sleep(1);
                Admin *u1 = new Admin(usuario, senha);
                _usuarios.push_back(u1);
                
                opcao = "Voltar";
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
                opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
            }
        } catch (usuario_ja_existe_e &e) {
            std::cout << "Usuario ja existe!" << std::endl;
            opcao = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
        }
    } while (opcao != "Voltar");
}

void Sistema::adicionarCorredor(Corredor *corredor){
    _mercado.adicionarCorredor(corredor);
}

void Sistema::adicionarCorredor(){
    limparTela();
    std::vector<std::string> corredores = _mercado.getTodasCategorias();
    std::cout << "\tAS CATEGORIAS JÁ EXISTENTE SÃO" << std::endl;
    for (std::string s : corredores){
        std::cout << "- " << s << std::endl;
    }
    std::cout << std::endl;
    std::string novaCategoria;
    while (true){
        novaCategoria = preencherString("Qual será a categoria do corredor que deseja criar");
        novaCategoria = stringPesquisa(novaCategoria);
        if ((corredorValido(novaCategoria)) == 1) break;
        std::cout << "A categoria escolhida já existe! Por favor, tente novamente." << std::endl;
    }
    std::string confirmacao = mostrarOpcoes("\n", {"Confirmar", "Voltar"}, 0);
    if (confirmacao == "Confirmar"){
        Corredor * c = new Corredor(novaCategoria);
        _mercado.adicionarCorredor(c);
        std::cout << "O corredor de categoria " << novaCategoria << " foi criado com sucesso!" << std::endl;
        sleep(1);
    }
}

bool Sistema::corredorValido(std::string categoria){
    bool valido = 1;
    for (std::string s : _mercado.getTodasCategorias()){
        if (s == categoria) valido = 0;
    }
    return valido;
}

void Sistema::removerCorredor(){
    std::string categoria;
    do{
        limparTela();
        std::vector<std::string> corredores = _mercado.getTodasCategorias();
        corredores.push_back("Voltar");
        categoria = mostrarOpcoes("\tSELECIONE O CORREDOR QUE DESEJA REMOVER", corredores, 1);
        if (categoria != "Voltar"){
            std::cout << "Tem certeza que deseja remover a categoria " << categoria << " ?" << std::endl;
            std::string confirmacao = mostrarOpcoes("\n", {"Confirmar", "Voltar"}, 0);
            if (confirmacao == "Confirmar"){
                try{
                    _mercado.removerCorredor(categoria);
                    std::cout << "O corredor de categoria " << categoria << " foi removido com sucesso!" << std::endl;
                    sleep(1);
                    categoria = "Voltar";
                }
                catch (std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    categoria = mostrarOpcoes("\n", {"Tentar Novamente", "Voltar"}, 0);
                }
            }
        }
    } while (categoria != "Voltar");
}

void Sistema::logarAdminstrador(const std::string &usuario, const std::string &senha) {
    try {
        std::pair<Conta *, bool> pair = encontrarUsuario(usuario, senha);
        if (pair.second == 1) throw std::invalid_argument("Erro no login!");

        _admin_logado = dynamic_cast<Admin *>(pair.first);
        paginaAdmin();
    } catch (usuario_invalido_e &e) {
        throw std::invalid_argument("Usuario nao encontrado!");
    } catch (senha_incorreta_e &e) {
        throw std::invalid_argument("Senha invalida!");
    }
}

void Sistema::logarConsumidor(const std::string &usuario, const std::string &senha) {
    try {
        std::pair<Conta *, bool> pair = encontrarUsuario(usuario, senha);
        if (pair.second == 0) throw std::invalid_argument("Erro no login!");

        _consumidor_logado = dynamic_cast<Consumidor *>(pair.first);
        paginaConsumidor();
    } catch (usuario_invalido_e &e) {
        throw std::invalid_argument("Usuario nao encontrado!");
    } catch (senha_incorreta_e &e) {
        throw std::invalid_argument("Senha invalida!");
    }
}

std::pair<Conta *, bool> Sistema::encontrarUsuario(const std::string &usuario, const std::string &senha) {
    bool e_consumidor;

    for (Conta *c : _usuarios) {
        if (c->getUsuario() == usuario) {
            if (c->verificarSenha(senha) == true) {
                try {
                    Consumidor c1 = dynamic_cast<Consumidor &>((*c));
                    e_consumidor = 1;
                } catch (std::bad_cast &e) {
                    e_consumidor = 0;
                }
                std::pair<Conta *, bool> retorno(c, e_consumidor);
                return retorno;
            }
            throw senha_incorreta_e();
        }
    }
    throw usuario_invalido_e();
}

void Sistema::verificarUsuario(const std::string &usuario) {
    for (Conta *c : _usuarios) {
        if (c->getUsuario() == usuario) throw usuario_ja_existe_e();
    }
}

void Sistema::verificarSenhaCadastro(const std::string &senha, const std::string &senha_novamente) {
    bool certa = (senha.find("12345") == std::string::npos) && (senha.find(" ") == std::string::npos) &&
                 (senha.size() >= 5 && senha.size() <= 50);

    if (!certa) throw std::invalid_argument("Senha invalida!");
    if (senha != senha_novamente) throw std::invalid_argument("As senhas nao coincidem!");
}

std::string Sistema::mostrarOpcoes(std::string titulo, std::vector<std::string> opcoes, bool limpar) {
    unsigned int escolha;
    bool flag = true;

    while (flag) {
        if (titulo == "\tUSUARIO LOGADO: ") {
            std::cout << titulo << _consumidor_logado->getUsuario();
            std::cout << "\t\tSaldo: R$" << std::fixed << std::setprecision(2) << _consumidor_logado->getSaldo() << std::endl;
        } else if (titulo == "\tADMINISTRADOR LOGADO: ")
            std::cout << titulo << _admin_logado->getUsuario() << std::endl;
        else if (titulo != "\n")
            std::cout << titulo << std::endl;

        for (unsigned int i = 0; i < opcoes.size(); i++) {
            std::cout << i + 1 << ". " << opcoes[i] << std::endl;
        }

        std::cin >> escolha;
        try {
            if (escolha > opcoes.size() || escolha == 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Escolha invalida!");
            }
            flag = false;
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            sleep(1);
            if (limpar) {
                limparTela();
            }
        }
    }
    std::cin.ignore(1000, '\n');
    return opcoes[escolha - 1];
}

void Sistema::adicionarConta(Conta *c) {
    _usuarios.push_back(c);
}

void Sistema::removerProduto(){
    std::string categoria;
    do{
        limparTela();
        std::vector<std::string> todasCategorias = _mercado.getTodasCategorias();
        todasCategorias.push_back("Voltar");
        categoria = mostrarOpcoes("\tEscolha a categoria do produto que deseja remover", todasCategorias, 1);

        std::string produto;
        if (categoria != "Voltar"){
            limparTela();
            std::vector<std::string> produtos = _mercado.getCorredor(categoria)->getNomeProdutos();
            produtos.push_back("Voltar");
            produto = mostrarOpcoes("Escolha o produto que deseja alterar", produtos, 1);
            if (produto != "Voltar") remocaoProdutoFinal(produto, categoria);
        }
    } while (categoria != "Voltar");
}

void Sistema::remocaoProdutoFinal(std::string produto, std::string categoria){
    Produto *escolha = _mercado.getProduto(produto);
    escolha->imprimirInformacoes();
    std::cout << "----------------------------" << std::endl;

    std::string opcao = mostrarOpcoes("\n", {"Excluir", "Reduzir Estoque", "Voltar"}, 0);
    if (opcao == "Reduzir Estoque"){
        unsigned int reducao = preencherInt("Quantas unidades deseja reduzir");
        if (reducao >= escolha->getQuantidade()){
            reducao = escolha->getQuantidade();
            escolha->removerEstoque(reducao);
            std::cout << "Todo o estoque foi removido com sucesso!" << std::endl;
            sleep(1);
        }
        else {
            escolha->removerEstoque(reducao);
            std::cout << "Você removeu " << reducao << " unidades do estoque com sucesso!" << std::endl;
            sleep(1);
        }
    }
    if (opcao == "Excluir"){
        _mercado.getCorredor(categoria)->removerProduto(produto);
        std::cout << "O produto " << produto << " foi excluido(a) com sucesso!" << std::endl;
        sleep(1);
    }
}

void Sistema::adicionarProduto() {
    std::string categoria;

    do {
        limparTela();
        std::vector<std::string> todasCategorias = _mercado.getTodasCategorias();
        todasCategorias.push_back("Voltar");
        categoria = mostrarOpcoes("\tEscolha a categoria do produto que deseja adicionar", todasCategorias, 1);
        limparTela();

        if (categoria == "Voltar") break;

        std::cout << "----------------------------" << std::endl;
        std::cout << "Os produtos em estoque da categoria " << categoria << " são: " << std::endl;
        Corredor *corredorEscolhido = _mercado.getCorredor(categoria);
        std::vector<std::string> produtos = corredorEscolhido->getNomeProdutos();

        for (auto produto : produtos) {
            std::cout << "- " << produto << std::endl;
        }
        std::cout << "----------------------------" << std::endl;

        std::string opcao =
            mostrarOpcoes("\tDESEJA ADICIONAR UM NOVO PRODUTO AO ESTOQUE OU ADICIONAR À UM JA EXISTENTE?",
                          {"Novo", "Ja Existente", "Voltar"}, 1);

        if (opcao == "Novo") {
            limparTela();
            try {
                Produto *produtoNovo = criarProduto();
                _mercado.adicionarNovoProduto(categoria, produtoNovo);
                std::cout << "O produto foi adicionado com Sucesso!" << std::endl;
                sleep(1);
            } catch (voltar_e &e) {
                std::cout << "Procedimento Cancelado." << std::endl;
                sleep(1);
            }
        }

        else if (opcao == "Ja Existente") {
            unsigned int quantidade;
            std::string confirmacao;
            std::string produtoNovo = paginaProdutosAdmin(categoria);
            limparTela();

            if (produtoNovo != "Voltar") {

                quantidade = preencherInt("Qual a quantidade a ser adicionada");
                std::cout << std::endl;

                std::cout << "Você está adicionando " << quantidade << " unidades ao produto " << produtoNovo << "."
                        << std::endl;
                confirmacao = mostrarOpcoesA("Deseja Confirmar A Adição?", {"Sim", "Cancelar"}, 0);

                if (confirmacao == "Sim") {
                    _mercado.adicionarProdutoJaExistente(categoria, produtoNovo, quantidade);
                    std::cout << "O produto foi adicionado com Sucesso!" << std::endl;
                    sleep(1);
                }
            }
        }
    } while (categoria != "Voltar");
}

Produto *Sistema::criarProduto() {
    Produto *novoProduto = nullptr;
    std::string confirmacao;

    do {
        std::string tipo = mostrarOpcoes("\tESCOLHA O TIPO DO PRODUTO", Produto::_tipos_de_produto, 1);

        if (tipo != "Voltar") {
            do {
                if (confirmacao == "Refazer") {
                    delete novoProduto;
                    limparTela();
                }
                std::string nome;

                while (true){
                    nome = preencherString("Nome");
                    nome = stringPesquisa(nome);
                    if (produtoValido(nome) == 1) break;
                    std::cout << "Já existe um produto com esse nome! Por favor, tente novamente." << std::endl;
                }
                //não colocar else if aqui
                if (tipo == "Produto Genérico") {
                    novoProduto = Produto::criarProdutoGenerico(nome);
                    confirmacao = novoProduto->confirmarComposicao();
                }
                else if (tipo == "Produto Alimentício") {
                    novoProduto = ProdutoAlimenticio::criarProdutoAlimenticio(nome);
                    confirmacao = novoProduto->confirmarComposicao();
                }
                else if (tipo == "Produto de Limpeza") {
                    novoProduto = ProdutoLimpeza::criarProdutoLimpeza(nome);
                    confirmacao = novoProduto->confirmarComposicao();
                }
                else if (tipo == "Produto Infantil") {
                    novoProduto = ProdutoInfantil::criarProdutoInfantil(nome);
                    confirmacao = novoProduto->confirmarComposicao();
                }
            } while (confirmacao == "Refazer");

            if (confirmacao == "Sim") {
                return novoProduto;
            }
            else if (confirmacao == "Cancelar") {
                delete novoProduto;
            }
        }
    } while (confirmacao == "Refazer");
    throw(voltar_e());
}

std::string Sistema::paginaProdutosAdmin(std::string categoria) {
    Corredor *corredor = _mercado.getCorredor(categoria);
    std::vector<std::string> produtos = corredor->getNomeProdutos();
    produtos.push_back("Voltar");
    limparTela();

    std::string opcao = mostrarOpcoes("ESCOLHA O PRODUTO DESEJADO", produtos, 1);
    return opcao;
}

bool Sistema::produtoValido(std::string nome){
    bool valido;
    try{
        _mercado.getProduto(nome);
        valido = 0;
    }
    catch (std::invalid_argument &e){
        valido = 1;
    }
    return valido;
}

void Sistema::apagarSistema(){
    for (Corredor* c : _mercado.getCorredores()){
        delete c;
    }
    for (Conta* c : _usuarios){
        delete c;
    }
}