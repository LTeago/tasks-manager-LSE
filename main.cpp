#include <iostream>
#include "list.h"

struct Tarefa
{
    int id;
    char descricao[101];
    int prioridade;
};

Tarefa criarTarefa()
{
    Tarefa t;
    std::cout << "Qual o ID da tarefa?\n";
    std::cin >> t.id;
    std::cin.ignore();
    std::cout << "Descreva a tarefa em até 100 caracteres\n";
    std::cin.getline(t.descricao, 101);
    std::cout << "Qual a prioridade da tarefa? Escolha entre 1 e 3.\n";
    std::cin >> t.prioridade;
    return t;
}

Tarefa removerPorId()
{

}

int main()
{
    sc::list<Tarefa> tarefas;
    int n;

    do
    {
        std::cout << "\nBem-vindo ao gerenciamento de tarefas!\n"
                  << "1 - Inserir nova tarefa\n"
                  << "2 - Remover tarefa pelo ID\n"
                  << "3 - Remover tarefas por prioridade\n"
                  << "4 - Buscar tarefa por ID\n"
                  << "5 - Exibir tarefas por prioridade\n"
                  << "0 - Sair\n";
        std::cin >> n;

        switch (n)
        {
        case 1:
            tarefas.push_back(criarTarefa());
            break;
        case 2:
        {
            int id;
            std::cout << "Digite o ID da tarefa a remover: ";
            std::cin >> id;
            //sc::removerPorId(tarefas, id);
            break;
        }
        case 3:
        {
            int prio;
            std::cout << "Digite a prioridade a remover: ";
            std::cin >> prio;
            //sc::removerPorPrioridade(tarefas, prio);
            break;
        }
        case 4:
        {
            int id;
            std::cout << "Digite o ID da tarefa a buscar: ";
            std::cin >> id;
            //sc::buscarPorId(tarefas, id);
            break;
        }
        case 5:
            //sc::exibirPorPrioridade(tarefas);
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
