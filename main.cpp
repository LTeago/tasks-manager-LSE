#include <iostream>
#include "list.hpp"

int main() {
    sc::list<Tarefa> tarefas;
    int n;

    do {
        std::cout << "\nBem-vindo ao gerenciamento de tarefas!\n"
                  << "1 - Inserir nova tarefa\n"
                  << "2 - Remover tarefa pelo ID\n"
                  << "3 - Remover tarefas por prioridade\n"
                  << "4 - Buscar tarefa por ID\n"
                  << "5 - Exibir tarefas por prioridade\n"
                  << "0 - Sair\n";
        std::cin >> n;

        switch (n) {
            case 1:
                inserirTarefa(tarefas);
                break;
            case 2: {
                int id;
                std::cout << "Digite o ID da tarefa a remover: ";
                std::cin >> id;
                removerPorId(tarefas, id);
                break;
            }
            case 3: {
                int prio;
                std::cout << "Digite a prioridade a remover: ";
                std::cin >> prio;
                removerPorPrioridade(tarefas, prio);
                break;
            }
            case 4: {
                int id;
                std::cout << "Digite o ID da tarefa a buscar: ";
                std::cin >> id;
                buscarPorId(tarefas, id);
                break;
            }
            case 5:
                exibirPorPrioridade(tarefas);
                break;
            case 0:
                std::cout << "Encerrando o programa.\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (n != 0);

    return 0;
}
