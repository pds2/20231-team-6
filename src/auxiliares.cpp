#include "../include/auxiliares.hpp"

void limparTela(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

std::string mostrarOpcoesA(std::string titulo, std::vector<std::string> opcoes, bool limpar){
  unsigned int escolha;
  bool flag = true;
  
  std::cout << titulo << std::endl;
  while (flag){
    for (unsigned int i = 0; i < opcoes.size(); i++){
    std::cout << i+1 << ". " << opcoes[i] << std::endl;
    }

    std::cin >> escolha;
    try{
      if (escolha > opcoes.size() || escolha == 0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
        throw std::invalid_argument("Escolha invalida!");
      }
      flag = false;
    }
    catch (std::invalid_argument &e){
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

std::string preencherString(std::string campo){
  std::cout << campo << ": ";
  std::string entrada;
  getline(std::cin, entrada);
  return entrada;
}

int preencherInt(std::string campo){
  int entrada = -1;
  while (true) {
    std::cout << campo << ": ";
    std::cin >> entrada;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Por favor, digite um número válido.\n";
    }
    else if (entrada <= 0) {
        std::cout << "O número deve ser maior que zero. Por favor, digite novamente.\n";
    }
    else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
  }
  return entrada;
}

double preencherDouble(std::string campo) {
    double entrada = -1.0;
    while (true) {
        std::cout << campo << ": ";
        std::cin >> entrada;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, digite um número válido.\n";
        }
        else if (entrada < 0.0) {
            std::cout << "O número deve ser maior que zero. Por favor, digite novamente.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return entrada;
}

std::string stringPesquisa(std::string entrada){
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