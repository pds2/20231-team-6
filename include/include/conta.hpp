#ifndef CONTA_HPP
#define CONTA_HPP

#include "produto.hpp"

#include <string>
#include <vector>

using namespace std;

/*
    @brief Definição da classe conta e seus métodos.
 */
class Conta {
    protected:
        //Construtor base de uma conta.
    Conta(const std::string& usuario, const std::string& senha);

    private:
        
        std::string usuario;
        std::string senha;

    public:
        virtual ~Conta();
        //Retorna o usuário
        std::string getUsuario() const;

        //Verifica se a senha é válida.
        bool verificarSenha(const std::string& senha) const;
        
        //Registra uma nova conta.
        void registrar(std::string usuario, std::string senha);
};

#endif
