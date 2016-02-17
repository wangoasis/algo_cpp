#include <list>
using namespace std;

list<int> Josephus(const int total, const int step) {
  
  list<int> ori = list<int>();
  list<int> result = list<int>();

  for(int i = 1; i <= total; i++) 
    ori.push_back(i);

  list<int>::const_iterator ite = ori.begin();

  int currentStep;
  int currentTotal = total;

  while(currentTotal > 0) {
    currentStep = 0;
    for(; currentStep < step; ) {
      ++currentStep;
      ++ite;
      if(ite == ori.end())
        ite = ori.begin();
    }
    result.push_back(*ite);
    ite = ori.erase(ite);
    if(ite == ori.end())
      ite = ori.begin();
    --currentTotal;
  }

  return result;
}