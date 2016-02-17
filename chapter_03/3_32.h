#ifndef queneMine_H
#define queneMine_H 
#include <stdio.h>
using namespace std;

template <typename Object>
class queneMine {
private:
  struct node
  {
    Object data;
    node* next;

    node (Object obj = Object())
    :data(obj) {}

  };

public:
  queneMine () {
    head = NULL;
    tail = NULL;
  }

  void enquene(const Object & x) {
    node* p = new node(x);
    if(tail) {
      tail->next = p;
      tail = p;
    }
    else {
      head = tail = p;
    }
  }

  const Object dequene () {
    Object x = head->data;
    if(head && (head == tail))
      head = tail = NULL;
    else {
      node* p = head;
      head = head->next;
      delete p;
    }
    return x;
  }

private:
  node* head;
  node* tail;
};
#endif