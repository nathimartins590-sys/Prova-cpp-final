    #include <iostream>

    using namespace std;

    struct Produto {
        int codigo;
        string nome;
        int quantidade;
        double preco;
    };

    int encontrarProduto(const vector<Produto>& estoque, int codigo) {
        for (size_t i = 0; i < estoque.size(); ++i) {
            if (estoque[i].codigo == codigo) {
                return i;
            }
        }
        return -1;
    }

    int main() {
        vector<Produto> estoque;
        int opcao;
        
        std::cout << "=== CONTROLE DE ESTOQUE - PEQUENO COMÉRCIO ===\n" <<  std::endl;
        
        do {
            std::cout << "\n--- MENU PRINCIPAL ---\n" <<  std::endl;
            std::cout << "1. Adicionar produto\n";
            std::cout << "2. Atualizar quantidade (entrada/saída)\n" << std::endl;
            std::cout << "3. Buscar produto\n";
            std::cout << "4. Listar todos os produtos\n" <<  std::endl;
            std::cout << "5. Remover produto\n" <<  std::endl;
            std::cout << "0. Sair\n" <<  std::endl;
            std::cout << "Escolha uma opção: " <<  std::endl;
            std::cin >> opcao;
            
            if (opcao == 1) { 
                Produto p;
                std::cout << "\n--- ADICIONAR PRODUTO ---\n" <<  std::endl;
                std::cout << "Código: " <<  std::endl;
                std::cin >> p.codigo;
                
                if (encontrarProduto(estoque, p.codigo) != -1) {
                    std::cout << "Erro: Código já existe!\n" <<  std::endl;
                    continue;
                }
                
                std::cin.ignore();
                std::cout << "Nome: " <<  std::endl;
                getline(cin, p.nome);
                std::cout << "Quantidade inicial: " <<  std::endl;
                std::cin >> p.quantidade;
                std::cout << "Preço unitário: R$ " <<  std::endl;
                std::cin >> p.preco;
                
                estoque.push_back(p);
                std::cout << "Produto adicionado com sucesso!\n" <<  std::endl;
                
            } else if (opcao == 2) { 
                int codigo, qtd;
                std::cout << "\n--- ATUALIZAR QUANTIDADE ---\n" <<  std::endl;
                std::cout << "Código do produto: " <<  std::endl;
                std::cin >> codigo;
                
                int idx = encontrarProduto(estoque, codigo);
                if (idx == -1) {
                    std::cout << "Produto não encontrado!\n" <<  std::endl;
                    continue;
                }
                
                std::cout << "Produto: " << estoque[idx].nome << " | Estoque atual: " << estoque[idx].quantidade << std::endl;
                std::cout << "Quantidade a adicionar (+) ou remover (-): " <<  std::endl;
                std::cin >> qtd;
                
                if (estoque[idx].quantidade + qtd < 0) {
                    std::cout << "Erro: Quantidade insuficiente!\n" <<  std::endl;
                } else {
                    estoque[idx].quantidade += qtd;
                    std::cout << "Quantidade atualizada! Novo estoque: " << estoque[idx].quantidade <<  std::endl;
                }
                
            } else if (opcao == 3) {
                int codigo;
                std::cout << "\n--- BUSCAR PRODUTO ---\n" <<  std::endl;
                std::cout << "Código: "  << std::endl;
                std::cin >> codigo;
                
                int idx = encontrarProduto(estoque, codigo);
                if (idx == -1) {
                    std::cout << "Produto não encontrado!\n" <<  std::endl;
                } else {
                    std::cout << "\nProduto encontrado:\n" <<  std::endl;
                    std::cout << "Código: " << estoque[idx].codigo <<  std::endl;
                    std::cout << "Nome: " << estoque[idx].nome <<  std::endl;
                    std::cout << "Quantidade: " << estoque[idx].quantidade <<  std::endl;
                    std::cout << fixed << setprecision(2) << "Preço: R$ " << estoque[idx].preco <<  std::endl;
                    std::cout << "Valor total em estoque: R$ " << (estoque[idx].quantidade * estoque[idx].preco) <<  std::endl;
                }
                
            } else if (opcao == 4) {
                std::cout << "\n--- LISTA DE PRODUTOS ---\n" <<  std::endl;
                if (estoque.empty()) {
                    std::cout << "Estoque vazio!\n" <<  std::endl;
                    continue;
                }
                
                std::cout << setw(6) << "Cód" << setw(25) << "Nome" << setw(12) << "Qtd" << setw(12) << "Preço" << setw(15) << "Total\n" <<  std::endl;
                std::cout << string(70, '-') <<  std::endl;
                
                double valorTotalGeral = 0;
                
                for (const auto& p : estoque) {
                    double total = p.quantidade * p.preco;
                    valorTotalGeral += total;
                    std::cout << setw(6) << p.codigo 
                        << setw(25) << p.nome.substr(0, 22)
                        << setw(12) << p.quantidade 
                        << setw(12) << fixed << setprecision(2) << p.preco
                        << setw(15) << total <<  std::endl;
                }
                
                std::cout << string(70, '-') <<  std::endl;
                std::cout << "Valor total do estoque: R$ " << valorTotalGeral <<  std::endl;
                
            } else if (opcao == 5) {
                int codigo;
                std::cout << "\n--- REMOVER PRODUTO ---\n" <<  std::endl;
                std::cout << "Código: " <<  std::endl;
                std::cin >> codigo <<  std::endl;
                
                int idx = encontrarProduto(estoque, codigo);
                if (idx == -1) {
                    std::cout << "Produto não encontrado!\n" <<  std::endl;
                } else {
                    std::cout << "Removendo: " << estoque[idx].nome <<  std::endl;
                    estoque.erase(estoque.begin() + idx);
                    std::cout << "Produto removido com sucesso!\n" <<  std::endl;
                }
            }
            
        } while (opcao != 0);
        
        std::cout << "\nPrograma encerrado. Obrigado por usar o sistema de controle de estoque!\n" <<  std::endl;
        return 0;
    }