#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP

#include <exception>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <limits>
#include <stdexcept>
#include <vector>
#include <typeinfo>

/*
* @brief Limpa a tela do console.
*/
void limparTela();

/*
* @brief Printa na tela todas as opções disponíveis para escolha do usuário,
* bem como um título para a página (opcional). Retorna a opção escolhida.
* @throws Lança uma exceção caso o usuário escolha uma opção inválida.
*/
std::string mostrarOpcoesA(std::string titulo, std::vector<std::string> opcoes, bool limpar);

/*
* @brief Printa na tela o que o usuário deve preencher e retorna a informação preenchida.
*/
std::string preencherString(std::string campo);

/*
* @brief Printa na tela o que o usuário deve preencher e retorna a informação preenchida.
*/
int preencherInt(std::string campo);

/*
* @brief Printa na tela o que o usuário deve preencher e retorna a informação preenchida.
*/
double preencherDouble(std::string campo);

/*
* @brief Recebe uma string, que deve ser formatada de acordo com o padrão de pesquisa:
* todas as palavras sempre começam com letra maiúscula.
*/
std::string stringPesquisa(std::string entrada);

//Vetor auxiliar com strings com o nome das subclasses.
std::vector <std::string> _tipos_de_produtoA = {"Produto Genérico", "Produto Alimentício", "Produto de Limpeza", \
"Produto Infantil", "Voltar"};

#endif