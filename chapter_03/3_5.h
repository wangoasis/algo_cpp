#include <list>
using namespace std;

template<typename Object>
list<Object> orList(const list<Object> & L1, const list<Object> & L2) {
  list<Object>::const_iterator ite_1 = L1.begin();
  list<Object>::const_iterator ite_2 = L2.begin();
  list<Object> result = list<Object>();

  while(ite_1 != L1.end() && ite_2 != L2.end()) {
    if(*ite_1 == *ite_2) {
      result.push_back(*ite_1);
      ++ite_1;
      ++ite_2;
    }
    else if(*ite_1 < *ite_2) {
      result.push_back(*ite_1);
      ++ite_1;
    }
    else {
      result.push_back(*ite_2);
      ++ite_2;
    }
  }

  while(ite_1 != L1.end()) {
    result.push_back(*ite_1);
    ++ite_1;
  }

  while(ite_2 != L2.end()) {
    result.push_back(*ite_2);
    ++ite_2;
  }

  return result;
}