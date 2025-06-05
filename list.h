#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <cassert>
#include <cstddef>
#include <iterator>

struct Tarefa
{
  int id;
  char descricao[101];
  int prioridade;
};

Tarefa criarTarefa()
{
  Tarefa t;
  std::cout << "-----------------------------\n";
  std::cout << "Qual a prioridade da tarefa? Escolha entre 1 e 3.\n";
  std::cin >> t.prioridade;
  if (t.prioridade < 1 || t.prioridade > 3)
  {
    std::cout << "Prioridade inválida. Válido somente entre 1 e 3\n";
    return criarTarefa();
  }
  std::cout << "Qual o ID da tarefa?\n";
  std::cin >> t.id;
  std::cin.ignore();
  std::cout << "Descreva a tarefa em até 100 caracteres\n";
  std::cin.getline(t.descricao, 101);
  std::cout << "Tarefa adicionada com sucesso.\n";
  std::cout << "-----------------------------\n";

  return t;
}
namespace sc
{

  template <typename T>
  class list
  {
  private:
    struct Node
    {
      T data;
      Node *next;

      Node(const T &d = T{}, Node *n = nullptr)
          : data{d}, next{n} {}
    };

    Node *head;
    std::size_t size_;

  public:
    list() : head(nullptr), size_(0) {}

    ~list()
    {
      clear();
    }
    [[nodiscard]] bool empty() const
    {
      return size_ == 0;
    }

    void push_back(const T &value)
    {
      Node *node = new Node(value);
      if (!head)
      {
        head = node;
      }
      else
      {
        Node *curr = head;
        while (curr->next)
          curr = curr->next;
        curr->next = node;
      }
      ++size_;
    }

    void clear()
    {
      while (head != nullptr)
      {
        Node *temp = head;
        head = head->next;
        delete temp;
      }
      size_ = 0;
    }

    void removerPorID(int id)
    {
      Node *atual = head;
      Node *aux = nullptr;

      if (empty())
      {
        std::cout << "Não há tarefas a serem removidas, adicione uma tarefa.\n";
        return;
      }

      while (atual)
      {
        if (atual->data.id == id)
        {
          if (aux)
          {
            aux->next = atual->next;
          }
          else
          {
            head = atual->next;
          }
          delete atual;
          --size_;
          std::cout << "Tarefa removida com sucesso.\n";
          return;
        }
        aux = atual;
        atual = atual->next;
      }
      std::cout << "Tarefa não encontrada.\n";
    }

    void exibirTarefas()
    {
      if (empty())
        std::cout << "Não há tarefas a serem exibidas, adicione uma tarefa.\n";
      for (int prioridade = 1; prioridade <= 3; ++prioridade)
      {
        Node *atual = head;
        while (atual)
        {
          if (atual->data.prioridade == prioridade)
          {
            std::cout << "-----------------------------\n";
            std::cout << "ID: " << atual->data.id << "\n";
            std::cout << "Prioridade: " << atual->data.prioridade << "\n";
            std::cout << "Tarefa: " << atual->data.descricao << "\n";
            std::cout << "-----------------------------\n";
          }
          atual = atual->next;
        }
      }
    }

    void buscarPorId(int id)
    {
      Node *atual = head;
      Node *aux = nullptr;

      while (atual)
      {
        if (atual->data.id == id)
        {
          std::cout << "-----------------------------\n";
          std::cout << "ID: " << id << "\n";
          std::cout << "Prioridade: " << atual->data.prioridade << "\n";
          std::cout << "Tarefa: " << atual->data.descricao << "\n";
          std::cout << "-----------------------------\n";
          return;
        }
        atual = atual->next;
      }
      std::cout << "Tarefa não encontrada";
    }
  };

} // namespace sc

#endif // LIST_HPP
