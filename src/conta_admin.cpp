#include <iostream>
#include <string>
#include <vector>

#include "../include/conta_admin.hpp"

Admin::Admin(const std::string& usuario, const std::string& senha) : Conta(usuario, senha){}

Admin::~Admin(){}