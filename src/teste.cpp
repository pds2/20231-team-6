


// class ConstrutorProduto {
//     public:
//         virtual Produto *build_produto(outrosargs) = 0; 
// }

// class ConstrutorArroz : public ConstrutorProduto {
//     public:
//         Produto *build_produto(outrosargs) override { return new Arroz };
// };


// class ConstrutorSabao : public ConstrutorProduto {
//     public:
//         Produto *build_produto(outrosargs) override { return new Sabao };
// };

// class ProdutoFactory {
//     private:
//         map<string, ConstrutorProduto *> construtores;
//     public:
//         ProdutoFactory() {
//             construtores["arroz"] = ConstrutorArroz();
//             construtores["sabao"] = ConstrutorSabao();
//         }
//         Produto *criar_produto(string nome, outrosargs) {
//             return construtores[nome].build_produto(outrosrgs);
//         }
// };