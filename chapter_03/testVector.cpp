#include "vectorMine.h"
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

int main () {

    vectorMine<string> v(4);
    v[0] = "aaaa";
    v[1] = "bbbb";
    v[2] = "cccc";
    v[3] = "dddd";
    
    for(auto &a : v) 
        cout << a << " ";
    cout << endl;
    
    v.pushBack("eeee");
    for(auto &a : v) 
        cout << a << " ";
    cout << endl;

    v.popBack();
    for(auto &a : v) 
        cout << a << " ";
    cout << endl;

    v.insert(v.end(), "ffff");
    for(auto &a : v) 
        cout << a << " ";
    cout << endl;

    v.erase(v.end()-1);
    for(auto &a : v) 
        cout << a << " ";
    cout << endl;
}
