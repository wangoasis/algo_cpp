#include <list>
#include <iostream>
using namespace std;
template<typename Object>
void printLots(list<Object> L, list<int> P) {

  list<int>::const_iterator pIter = P.begin();
  list<Object>::const_iterator lIter = L.begin();
  int start = 0;
  for(; pIter != P.end(); ++pIter) {
    while(start != *pIter && lIter != L.end()) {
      ++start;
      ++lIter;
    }
    if(lIter != L.end())
      cout << *lIter << endl;
    else
      break;
  }
}