#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <cassert>
#include <cstddef>
#include <iterator>

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
      Node *anterior = nullptr;

      if (empty())
        throw std::out_of_range("Não há tarefas a serem removidas, adicione uma tarefa.");

      while (atual)
      {
        if (atual->data.id == id)
        {
          if (anterior)
          {
            anterior->next = atual->next;
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
        anterior = atual;
        atual = atual->next;
      }
      std::cout << "Tarefa não encontrada.\n";
    }

    void exibirTarefas()
    {
      if (empty())
        throw std::out_of_range("Não há tarefas a serem exibidas, adicione uma tarefa.");
      for (int prioridade = 1; prioridade <= 3; ++prioridade)
      {
        Node *atual = head;
        while (atual)
        {
          if (atual->data.prioridade == prioridade)
          {
            std::cout << "ID: " << atual->data.id << "\n";
            std::cout << "Prioridade: " << atual->data.prioridade << "\n";
            std::cout << "Tarefa: " << atual->data.descricao << "\n";
            std::cout << "-----------------------------\n";
          }
          atual = atual->next;
        }
      }
    }
  };

} // namespace sc

#endif // LIST_HPP
