#ifndef simpleList_H
#define simpleList_H
#include <stdlib.h>
using namespace std;

template<typename Object>
/*
  a single-directional list
*/
class simpleList {
private:
  struct Node
  {
    Object data;
    Node* next;

    Node (const Object & x = Object(), Node* n = NULL)
    : data(x), next(n) {}

  };

public:
  simpleList() {
    init();
  }

  int size() const {
    return theSize;
  }

  bool contains(const Object & x) const {
    Node* node = head->next;
    while(node != NULL && node->data != x) {
      node = node->next;
    }
    if(node == NULL)
      return false;
    else 
      return true;
  }

  bool add(const Object & x) {
    Node* node = head->next;
    Node* node2 = head;
    while(node != NULL && node->data < x) {
      node = node->next;
      node2 = node2->next;
    }
    if(node != NULL && node->data == x)
      return false;
    else {
      Node* newNode = new Node(x, node);
      node2->next = newNode;
      theSize++;
      return true;
    }
  }

  bool remove(const Object & x) {
    Node* node = head->next;
    Node* node2 = head;
    while(node != NULL && node->data != x) {
      node = node->next;
      node2 = node2->next;
    }
    if(node == NULL)
      return false;
    else {
      node2->next = node->next;
      delete node;
      theSize--;
      return true;
    }
  }

  void printList() {
    Node* node = head->next;
    while(node != NULL) {
      cout << node->data << endl;
      node = node->next;
    }
  }

private:

  void init() {
    head = new Node;
    head->next = NULL;
    theSize = 0;
  }

  Node* head;
  int theSize;
};

#endif