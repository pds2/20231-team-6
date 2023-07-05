#include "../include/conta.hpp"

Conta::Conta(const std::string& usuario, const std::string& senha): _usuario(usuario), _senha(senha){};

Conta::~Conta(){}

std::string Conta::getUsuario() const{
  return _usuario;
}

bool Conta::verificarSenha(const std::string& senha) const{
  return (_senha == senha);
}

void Conta::trocarSenha(std::string const &senha){
  _senha = senha;
}