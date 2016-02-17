#include <stdio.h>
using namespace std;

#ifndef stackMine_H
#define stackMine_H

template <typename Object>
class stackMine {
private:
  struct node
  {
    /* data */
    Object data;
    node* next;

    node () {}
    node (Object obj) : data(obj) {}
    node (Object obj, node* n) : data(obj), next(n) {}
  };

public:
  stackMine () {
    head = NULL;
  }

  void push(const Object & x) {
    node* p = new node(x, head);
    head = p;
  }

  const Object & top() {
    return head->data;
  }

  void pop() {
    node* p = head->next;
    delete head;
    head = p;
  }

private:
  node* head;
};
#endif