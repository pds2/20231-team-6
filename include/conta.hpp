#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>
using namespace std;


//considerando que o maior tamanho possivel de input e 999 caracteres
#define TAMANHO_MAXIMO 999

class Conta {
	private:
		char* usuario;
		char* senha;
		int tamanho_usuario;
		int tamanho_senha;
		int saldo;
	public:
		Conta(char* usuario, char* senha, int tamanho_usuario, int tamanho_senha, int saldo);
		void inicializar_saldo();
		void alterar_saldo(int alteracao);

};

void registrar();
void login();
int verificar_validade_usuario(char* usuario, int tamanho_usuario, int numero_de_contas, Conta* contas);
int verificar_validade_senha(char* senha, int tamanho_senha);
int verificar_alfanumerico(char* string_check);
void verificar_numero_de_contas(int *numero_de_contas);
Conta* recuperar_dados_conta(Conta* contas, int numero_de_contas);
void resetar_senha(Conta resetar_conta, int numero_da_conta);

#endif

