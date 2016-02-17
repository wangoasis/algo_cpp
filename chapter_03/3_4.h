#include <list>
using namespace std;

template<typename Object>
// and operation of two sorted list
list<Object> andList(const list<Object> & L1, const list<Object> & L2) {
  list<Object>::const_iterator ite_1 = L1.begin();
  list<Object>::const_iterator ite_2 = L2.begin();
  list<Object> result = list<Object>();

  for(; ite_1 != L1.end(); ++ite_1) {
    while(ite_2 != L2.end() && *ite_2 < *ite_1) 
      ++ite_2;
    if(ite_2 == L2.end())
      break;
    else if(*ite_2 == *ite_1)
      result.push_back(*ite_1);
  }

  return result;
}