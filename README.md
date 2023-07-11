# **Sistema de Mercado**
O programa **Sistema De Mercado** tem como objetivo simular um sistema local de gerenciamento de estoque e vendas para um mercado, permitindo o acesso de consumidores e administradores, por meio de um login e senha.
## Sumário
1. [Participantes](#participantes)
2. [Funcionalidades do Sistema](#funcionalidades-do-sistema)
    1. [Funcionalidades para os Clientes](#funcionalidades-para-os-clientes)
    2. [Funcionalidades para os Administradores](#funcionalidades-para-os-administradores)
3. [User Stories](#user-stories)
    1. [Como Cliente](#como-Cliente)
    2. [Como Administrador](#como-Administrador)
4. [Pré-requisitos](#pré-requisitos)
5. [Instruções de Execução](#instruções-de-execução)

## **Participantes**
* [Arthur Rodrigues Chagas](https://github.com/arthurchagas1)
* [Arthur Rodrigues Diniz](https://github.com/TutiDiniz)
* [Caio Santana Trigueiro](https://github.com/caio-santt)
* [Yan Aquino Amorim](https://github.com/YanAquinoo)

## **Funcionalidades do Sistema**
O programa **Sistema de Mercado** oferece diversas funcionalidades para consumidores e administradores, visando facilitar o gerenciamento de estoque e as compras.

### Funcionalidades para os Clientes:
* **Busca de produtos:** Os clientes podem buscar produtos de forma direta, através de seu nome, para encontrar os itens desejados.
* **Categorias de produtos:** Os produtos estão listados e separados em corredores, permitindo que os clientes encontrem novos itens navegando por corredores específicos, como: alimentos, produtos de limpeza, produtos infantis, entre outros.
* **Carrinho de compras:** Os clientes podem visualizar o seu carrinho, com todos os produtos e o preço total, antes de finalizar sua compra.
* **Histórico de compras:** Os clientes têm acesso ao seu histórico de compras, onde podem verificar os produtos adquiridos anteriormente, com a possibilidade de comprá-los novamente.
* **Cadastro de clientes:** Novos clientes podem se cadastrar facilmente no sistema, através de um login exclusivo e uma senha.
* **Saldo do cliente:** Quando se cadastra, o cliente recebe um saldo em dinheiro que pode ser visualizado e utilizado para efetuar compras no sistema.
* **Troca de senha:** Os clientes têm a possibilidade de trocar sua senha com facilidade, caso desejem.

### Funcionalidades para os Administradores:
* **Adição de novos produtos:** Os administradores podem criar e adicionar novos produtos ao estoque, informando dados importantes específicos de cada tipo de produto, como: data de validade, peso, cor, entre outros.
* **Edição de produtos já existentes:** Os administradores podem editar os produtos com facilidade, realizando atualizações nos preços e adicionando e removendo ao estoque, garantindo que o mercado esteja sempre atualizado.
* **Criação de contas administradoras:** Por segurança, apenas os administradores podem criar novas contas administradoras, permitindo que novos funcionários tenham acesso ao sistema com as permissões adequadas.
* **Gestão de usuários:** Os administradores têm acesso direto aos usuários do sistema, podendo remover clientes e alterar manualmente algumas informações deles, garantindo um controle adequado sobre os usuários cadastrados.

## **User Stories**

### **Como Cliente:**

* Quero encontrar produtos de forma direta e fácil, para realizar minhas compras.
    * [CRITERIOS DE ACEITAÇÃO]

      • O cliente deve estar cadastrado

      • Os produtos devem ter sido listados por um administrador

      • O cliente deve ter saldo em conta
* Quero ter acesso a uma página com todos os produtos separados por categorias, para encontrar novos produtos.
    * [CRITERIOS DE ACEITAÇÃO]

      • O cliente deve estar logado para visualizar o mercado

      • A página que o cliente procura deve existir

  •Os produtos devem estar cadastrados no mercado
* Quero ter acesso aos produtos que eu já comprei anteriormente, para organizar minhas compras ou comprá-los novamente.
    * [CRITERIOS DE ACEITAÇÃO]

      • O cliente tem que ter comprado algum produto anteriormente

      • O mercado deve ter o produto em estoque para que uma nova compra seja realizada
* Quero ter a possibilidade de trocar de senha com facilidade e segurança, para evitar que minha conta seja acessada por pessoas mal intencionadas.
    * [CRITERIOS DE ACEITAÇÃO]

      • O cliente deve conhecer a senha cadastrada anteriormente

      • O cliente deve ter sido registrado no passado

### **Como Administrador:**
* Quero ter a possibilidade de editar a página de produtos com facilidade, para sempre manter o meu mercado atualizado.
    * [CRITERIOS DE ACEITAÇÃO]

      • Deve existir um administrador com acesso ao mercado

      • A página de produtos deve ter a opção de receber novos produtos ou de excluir produtos já existentes
* Quero ter a possibilidade de criar novas contas administradoras com segurança, para disponibilizá-las para meus novos funcionários.
    * [CRITERIOS DE ACEITAÇÃO]

      • O administrador deve estar logado

      • O administrador deve ter acesso às contas dos funcionarios
* Quero ter acesso direto aos usuários do sistema, para remover pessoas indesejadas e alterar manualmente algumas informações dos clientes.
    * [CRITERIOS DE ACEITAÇÃO]

      • O usuário a ser removido deve ter sido logado anteriormente no sistema

      • As informações a serem alteradas devem estar presentes na definição do usuário

## **Pré-requisitos**
* Sistema operacional Linux
* Compilador g++ (GNU C++ Compiler)
* GNU Make
* Git
  
## **Instruções de Execução no Terminal** 
1. Clone este repositório localmente com o comando: `git clone https://github.com/pds2/20231-team-6.git`
2. Navegue até o diretório raiz do projeto: `cd 20231-team-6`
3. Para compilar e rodar os testes (tester.cpp) basta utilizar o comando: `make tests`
4. Para compilar o código principal (main.cpp) utilize o comando: `make` 
5. Execute o programa através do executável gerado com o comando: `./bin/main`
6. Como usar: Siga as instruções fornecidas pelo programa para utilizá-lo intuitivamente.
