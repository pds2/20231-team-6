#include "../include/conta.hpp"

Conta::Conta(const string& usuario, const string& senha): _usuario(usuario), _senha(senha){};

Conta::~Conta(){}

std::string Conta::getUsuario() const{
  return _usuario;
}

bool Conta::verificarSenha(const std::string& senha) const{
  return (_senha == senha);
}

void Conta::trocarSenha(string const &senha){
  _senha = senha;
}