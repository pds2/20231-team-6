#ifndef CONTA_HPP
#define CONTA_HPP

#include <string>
#include <vector>
#include <iomanip>

/*
    @brief Definição da classe conta e seus métodos.
 */
class Conta {
    protected:
        //Construtor base de uma conta.
    Conta(const std::string& usuario, const std::string& senha);

    private:
        std::string _usuario;
        std::string _senha;

    public:
        virtual ~Conta();
        //Retorna o usuário
        std::string getUsuario() const;

        //Verifica se a senha é válida.
        bool verificarSenha(const std::string& senha) const;

        //Troca senha do usuario.
        void trocarSenha(std::string const &senha);
};

#endif // CONTA_HPP