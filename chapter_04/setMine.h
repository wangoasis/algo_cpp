#ifndef setMine_H
#define setMine_H
using namespace std;
/*
  a set is a binary search tree with iterator
*/
template <typename Comparable>
class setMine {
private:
  struct setNode
  {
    Comparable data;
    setNode* left;
    setNode* right;
    setNode* parent;

    setNode () {
      left = NULL;
      right = NULL;
      parent = NULL;
    }

    setNode (const Comparable & x) {
      data = x;
      left = NULL;
      right = NULL;
      parent = NULL;
    }

    setNode (const Comparable & x, setNode* l, setNode* r, setNode* p)
    : data(x), left(l), right(r), parent(p) {}
  };

public:
  class const_iterator {
  public:
    const_iterator()
    :current(NULL) {}

    const Comparable & operator * () const {
      return retrieve();
    }

    const_iterator & operator ++ () {
      setNode<Comparable>* t;
      if(current->right) {
        t = current->right;
        while(t->left) 
          t = t->left;
        current  = t;
      }
      else {
        t = current->parent;
        while(t && t->data < current->data)
          t = t->parent;
        current = t;
      }
      return *this;
    }

    const_iterator operator ++ (int) {
      const_iterator old = *this;
      ++(*this);
      return old;
    }

    bool operator == (const const_iterator & rhs) const {
      return current == rhs.current;
    }

    bool operator != (const const_iterator & rhs) const {
      return !(*this == rhs);
    }

  protected:
    setNode* current;

    Comparable & retrieve() const {
      return current->data;
    }

    const_iterator(setNode* p)
    : current(p) {}

    friend class setMine;
  };

  class iterator : public const_iterator {
  public:
    iterator () {}

    iterator (setNode* p)
    : const_iterator(p) {}

    Comparable & operator * () {
      return const_iterator::retrieve();
    }

    const Comparable & operator * () const {
      return const_iterator::operator*();
    }

    iterator & operator ++ () {
      setNode* t;
      if(current->right) {
        t = current->right;
        while(t->left) 
          t = t->left;
        current  = t;
      }
      else {
        t = current->parent;
        while(t && t->data < current->data)
          t = t->parent;
        current = t;
      }
      return *this;
    }

    iterator operator ++ (int) {
      iterator old = *this;
      ++(*this);
      return old;
    }

    friend class setMine;
  };

public:
  setMine () {
    root = NULL;
  }

  setMine (const setMine & rhs) {
    if(this != &rhs)
      *this = rhs;
  }

  const setMine & operator = (const setMine & rhs) {
    if(this != &rhs) {
      makeEmpty();
      root = clone(rhs.root);
    }
    return *this;
  }

  ~setMine () {
    makeEmpty();
  }

  iterator contains(const Comparable & x) const {
    return contains(x, root);
  }

  iterator begin() const {
    setNode* t = root;
    while(t->left)
      t = t->left;
    return iterator(t);
  }

  bool isEmpty() const {
    return size() == 0;
  }

  int size () const {
    return size(root);
  }

  iterator insert(const Comparable & x) {
    return insert(x, root, root);
  }

  void makeEmpty () {
    makeEmpty(root);
  }

private:
  setNode* root;

  iterator insert(const Comparable & x, setNode* & t, setNode* p) {
    if(t == NULL) {
      t = new setNode(x, NULL, NULL, p);
      return iterator(t);
    }
    else if(x < t->data)
      return insert(x, t->left, t);
    else if(x > t->data) 
      return insert(x, t->right, t);
    return iterator(t);
  }

  iterator contains(const Comparable & x, setNode* node) const {
    if(node == NULL)
      return NULL;
    if(x < node->data)
      return contains(x, node->left);
    else if(x > node->data)
      return contains(x, node->right);
    else 
      return iterator(node);
  }

  void makeEmpty(setNode* node) {
    if(node != NULL) {
      makeEmpty(node->left);
      makeEmpty(node->right);
      delete node;
    }
    node = NULL;
  }

  int size (setNode * node) const {
    if(node == NULL)
      return 0;
    else
      return 1 + size(node->left) + size(node->right);
  }
};

#endif