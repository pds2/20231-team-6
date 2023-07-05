#include <cctype>
#include <stdexcept>

#include "../include/sistema.hpp"

Sistema::Sistema(){}; // Carrega todas as informacoes DO banco de dados

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
            // Chamar uma funcao para carregar todas as informacoes NO banco de dados
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
                
                sleep(2);
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
                paginaRemoverProduto();
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
    std::string opcao = mostrarOpcoes("\n", {"Adicionar ao Carrinho", "Voltar"}, 0);

    while (opcao != "Voltar") {
        unsigned int quantidade;

        std::cout << "Digite a Quantidade que Deseja Comprar: ";
        while (!(std::cin >> quantidade)) {
            std::cout << "Quantidade Invalida! Por Favor Tente Novamente: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (quantidade > escolha->getQuantidade()) {
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

void Sistema::paginaRemoverProduto() {
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
            {"Editar Produtos", "Edtiar Corredores", "Editar Usuarios", "Criar Conta Admin", "Deslogar"}, 1);

        if (opcao == "Editar Produtos") {
            adicionarProduto();
        }

        if (opcao == "Deslogar") {
            _admin_logado = nullptr;
            break;
        }
    }
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

void Sistema::adicionarMercado(Mercado m) {
    _mercado = m;
}

std::string Sistema::mostrarOpcoes(std::string titulo, std::vector<std::string> opcoes, bool limpar) {
    unsigned int escolha;
    bool flag = true;

    while (flag) {
        if (titulo == "\tUSUARIO LOGADO: ") {
            std::cout << titulo << _consumidor_logado->getUsuario();
            std::cout << "\t\tSaldo: R$" << _consumidor_logado->getSaldo() << std::endl;
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

/*string Sistema::escolherTipo(){
    limparTela();
    std::string opcao = mostrarOpcoes("\tESCOLHA O TIPO DO PRODUTO", Produto::_tipos_de_produto, 1);
      if(opcao != "Voltar"){
        return opcao;
      }
}*/

/*string Sistema::escolherCorredor(){
    limparTela();
    std::string voltar = "Voltar";
    std::vector<std::string> corredores;
    for(auto corredor : _mercado.getCorredores()){
      corredores.push_back(corredor->getCategoria());
    }
    corredores.push_back(voltar);

    std::string opcao = mostrarOpcoes("\tESCOLHA A CATEGORIA DO PRODUTO", corredores, 1);
      if(opcao != voltar){
      return opcao;
    }
}*/

void Sistema::adicionarProduto() {
    std::string categoria;

    do {
        limparTela();
        std::vector<std::string> todasCategorias = _mercado.getTodasCategorias();
        todasCategorias.push_back("Voltar");
        categoria = mostrarOpcoes("\tESCOLHA A CATEGORIA DO PRODUTO", todasCategorias, 1);
        limparTela();

        if (categoria == "Voltar") break;

        std::cout << std::endl;
        std::cout << "Os produtos em estoque da categoria " << categoria << " são: " << std::endl;
        Corredor *corredorEscolhido = _mercado.getCorredor(categoria);
        std::vector<std::string> produtos = corredorEscolhido->getNomeProdutos();

        for (auto produto : produtos) {
            std::cout << "- " << produto << std::endl;
        }
        std::cout << std::endl;

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

            if (produtoNovo == "Voltar") break;

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
                //não colocar else if aqui
                if (tipo == "Produto Genérico") {
                    novoProduto = Produto::criarProdutoGenerico();
                    confirmacao = novoProduto->confirmarComposicao();
                }
                else if (tipo == "Produto Alimentício") {
                    novoProduto = ProdutoAlimenticio::criarProdutoAlimenticio();
                    confirmacao = novoProduto->confirmarComposicao();
                }
                else if (tipo == "Produto de Limpeza") {
                    novoProduto = ProdutoLimpeza::criarProdutoLimpeza();
                    confirmacao = novoProduto->confirmarComposicao();
                }
                else if (tipo == "Produto Infantil") {
                    novoProduto = ProdutoInfantil::criarProdutoInfantil();
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