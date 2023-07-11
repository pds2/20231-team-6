#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <typeinfo>
#include <unistd.h>
#include <vector>

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
 * @brief Printa na tela qual informação o usuário deve preencher e retorna a informação preenchida.
 */
std::string preencherString(std::string campo);

/*
 * @brief Printa na tela qual informação o usuário deve preencher e retorna a informação preenchida.
 */
int preencherInt(std::string campo);

/*
 * @brief Printa na tela qual informação o usuário deve preencher e retorna a informação preenchida.
 */
double preencherDouble(std::string campo);

/*
 * @brief Recebe uma string, que deve ser formatada de acordo com o padrão de pesquisa:
 * todas as palavras sempre começam com letra maiúscula.
 */
std::string stringPesquisa(std::string entrada);

#endif // AUXILIARES_HPP