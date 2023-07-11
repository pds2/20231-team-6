#ifndef CONTA_ADMIN_HPP
#define CONTA_ADMIN_HPP

#include <string>
#include <vector>

#include "conta.hpp"

// Classe admin que herda de Conta. Representa uma conta de adminstrador.
class Admin : public Conta {
  public:
    // Construtor de uma conta específica para um admin.
    Admin(const std::string &usuario, const std::string &senha);

    ~Admin() override;
};

#endif // CONTA_ADMIN_HPP