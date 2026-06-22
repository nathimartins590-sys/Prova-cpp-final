# Prova-cpp
prova de c++


Nome: Nathalia Martis Correa

Curso: Informatica para internet

Unidade: UC 6: desenvolver algoritimos

Por que?: O tema escolhido foi controle de estoque de um pequeno comercio, o sistema faz armazenamentos, registros e remoção, o problema era que o pequeno comercio não conseguia registrar produtos, seus preços e suas quantidades.

Decisões tecnicas: A Estrutura de Dados

std::vector<Produto>:
Fácil de usar, redimensionável automaticamente e tem uma boa performance para quantidade pequena/média de produtos.
Decisão consciente de não usar std::map ou unordered_map (por código) para manter a simplicidade.

A Busca de Produtos

A busca é linear, complexidade O(n), aceitável para < 500 produtos.
Decisão: simplicidade > performance.

O Tratamento de Entrada

Mistura de cin >> e getline(cin, string) com cin.ignore() para lidar com o problema clássico do buffer do cin.
As validações básicas são de impedimento de códigos duplicados e bloqueio de quantidade negativa.

A Interface do Usuário

Menu textual em loop do-while.
O uso de <iomanip> (setw, fixed, setprecision(2)) para formatação profissional da tabela, o Feedback fica claro para o usuário em todas as operações.

As Bibliotecas Utilizadas

Apenas Standard Library:
iostream

E com zero dependências externas → fácil compilar em qualquer máquina com g++!

Limitações Técnicas (intencionais):

Dados são perdidos ao fechar o programa, buscar só por código e não tem histórico de movimentações.
