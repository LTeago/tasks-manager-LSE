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
    struct Tarefa
    {
      int id;
      char descricao[101]; 
      int prioridade; 
    };

    Node *head;
    std::size_t size_;

  public:
    list() : head(nullptr), size_(0) {}

    ~list()
    {
      clear();
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
    Tarefa criarTarefas(){
      Tarefa t;
      std::cout << "Qual o ID da tarefa?\n";
      std::cin >> t.id;
      std::cin.ignore();
      std::cout << "Descreva a tarefa em até 100 caracteres\n";
      std::cin.getline(t.descricao, 101);
      std::cout << "Qual a prioridade da tarefa? Escolha entre 1 e 3.";
      std::cin >> t.prioridade;
      return t;
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
  };

} // namespace sc

#endif // LIST_HPP
