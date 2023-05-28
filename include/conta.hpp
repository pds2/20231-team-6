#ifndef CONTA_HPP
#define CONTA_HPP

#include <string>
#include <vector>

/*
 definicao da classe conta, bem como seus metodos
 */

class Conta {
private:
    
    std::string usuario;
    std::string senha;
    std::vector<std::string> produtosComprados;

public:
    //construtor
    Conta(const std::string& usuario, const std::string& senha);
    //retorna o usuario
    std::string getUsuario() const;
    //
    bool verificarSenha(const std::string& senha) const;
    void adicionarProdutoComprado(const std::string& produto);
    void exibirProdutosComprados() const;
};

#endif
