#include <stack>
using namespace std;

#ifndef stackFastFindMin_H
#define stackFastFindMin_H

template <typename Object>
class stackFastFindMin {
public:

  void push(const Object & x) {
    objects.push(x);
    if(min.empty())
      min.push(x);
    else if(x <= min.top())
      min.push(x);
  }

  bool pop() {
    if(!objects.empty()) {
      Object x = objects.top();
      objects.pop();
      if(x == min.top()) 
        min.pop();
      return true;
    }
    return false;
  }

  const Object & minOfStack() const {
    return min.top();
  }

private:
  stack<Object> objects;
  stack<Object> min;
};
#endif