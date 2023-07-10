#include "../include/sistema.hpp"
#include "../include/auxiliar_main.hpp"

int main() {
    Sistema system;

    adicionar_corredor_alimentos(system);
    adicionar_corredor_vestimentas(system);
    adicionar_corredor_limpeza(system);
    adicionar_corredor_infantil(system);
    adicionar_consumidores(system);
    adicionar_admins(system);

    system.paginaInicial();

    return 0;
}
