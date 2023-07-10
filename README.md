# **Sistema de Mercado**
O programa **Sistema De Mercado** tem como objetivo simular um sistema local de gerenciamento de estoque e vendas para um mercado, permitindo o acesso de consumidores e administradores, por meio de um login e senha.
## Sumário
1. [Participantes](#participantes)
2. [Funcionalidades do Sistema](#funcionalidades-do-sistema)
    1. [Funcionalidades para os Usuários](#funcionalidades-para-os-usuários)
    2. [Funcionalidades para os Administradores](#funcionalidades-para-os-administradores)
3. [User Stories](#user-stories)
    1. [Como cliente](#como-cliente)
    2. [Como administrador](#como-administrador)
4. [Pré-requisitos](#pré-requisitos)
5. [Instruções para Uso](#instruções-para-uso)

## **Participantes**
* [Arthur Rodrigues Chagas](https://github.com/arthurchagas1)
* [Arthur Rodrigues Diniz](https://github.com/TutiDiniz)
* [Caio Santana Trigueiro](https://github.com/caio-santt)
* [Yan Aquino Amorim](https://github.com/YanAquinoo)

## **Funcionalidades do Sistema**
O programa **Sistema de Mercado** oferece diversas funcionalidades para consumidores e administradores, visando facilitar o gerenciamento de estoque e as compras.

### Funcionalidades para os Usuários:
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

### **Como cliente:**
* Quero encontrar produtos de forma direta e fácil, para realizar minhas compras.
* Quero ter acesso a uma página com todos os produtos separados por categorias, para encontrar novos produtos.
* Quero ter acesso aos produtos que eu já comprei anteriormente, para organizar minhas compras ou comprá-los novamente.
* Quero ter a possibilidade de trocar de senha com facilidade e segurança, para evitar que minha conta seja acessada por pessoas mal intencionadas.

### **Como administrador:**
* Quero ter a possibilidade de editar a página de produtos com facilidade, para sempre manter o meu mercado atualizado.
* Quero ter a possibilidade de criar novas contas administradoras com segurança, para disponibilizá-las para meus novos funcionários.
* Quero ter acesso direto aos usuários do sistema, para remover pessoas indesejadas e alterar manualmente algumas informações dos clientes.

## **Pré-requisitos**
* Sistema operacional Linux
* Compilador g++ (GNU C++ Compiler)
* GNU Make
* Git
  
## **Instruções para Uso**
1. Clone este repositório localmente: `git clone https://github.com/pds2/20231-team-6.git`
2. Navegue até o diretório raiz do projeto: `cd 20231-team-6`
3. Compile o código utilizando o comando `make`
4. Execute o programa: `./program/main`
5. Siga as instruções fornecidas pelo programa para utilizá-lo.
