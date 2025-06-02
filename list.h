#ifndef LIST_HPP
#define LIST_HPP

#include <iostream> // cout, endl

#include <cassert>  // assert()
#include <cstddef>  // std::ptrdiff_t
#include <iterator> // bidirectional_iterator_tag

namespace sc
{

  template <typename T>
  class list
  {
  private:
    //=== the data node.
    struct Node
    {
      T data; // Tipo de informação a ser armazenada no container.
      Node *next;
      Node *prev;

      Node(const T &d = T{}, Node *n = nullptr)
          : data{d}, next{n} { /* empty */ }
    };

  public:
    void push_back(const T &val)
    {
      Node *new_node{new Node(val, m_tail, m_tail->prev)};

      m_tail->prev->next = new_node;
      m_tail->prev = new_node;

      ++m_len;
    }
  };
}

#endif