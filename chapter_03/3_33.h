#ifndef vectorQuene_H
#define vectorQuene_H
#include <vector>
using namespace std;

template <typename Object>
class vectorQuene {
public:
  vectorQuene(int s)
  : maxSize(s),
    front(0),
    back(0) {
      v.resize(maxSize);
  }

  void enquene(const Object & x) {
    if(!full()) {
      v[back] = x;
      back = (back+1) % maxSize;
    }
  }

  const Object & dequene() {
    Object temp;
    if(!empty()) {
      temp = v[front];
      front = (front+1)%maxSize;
      return temp;
    }
    return NULL;
  }

  bool empty() const {
    return front == back;
  }

  bool full() const {
    return ((front - 1) % maxSize) == (back % maxSize);
  }
private:
  int front, back;
  int maxSize;
  vector<Object> v;
};
#endif