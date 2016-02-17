#include "test.h"
using namespace std;

int main () {
    
    setMine<int> s;
    for(int i = 5; i > 0; i--)
        s.insert(i);
    for(int i = 6; i < 10; i++)
        s.insert(i);
    cout << s.size() << " " << *(s.begin()) << endl;
    setMine<int>::iterator itr = ++s.begin();
    cout << *(itr) << endl;
}
