#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {
  private:
    static int _proximoId;
    int _id;
    std::string _nome;
    int _quantidade;
    double _preco;
    double _desconto = 0;

  public:
    Produto(const std::string &nome, int quantidade, int preco);
    virtual void imprimir_informacoes();
    void aplicar_desconto(double desconto);
    int get_id();
    std::string get_nome();
    double get_desconto();
    double get_preco();
    int get_quantidade();
};

#endif // PRODUTO_HPP