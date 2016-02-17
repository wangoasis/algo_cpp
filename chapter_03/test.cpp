#include "3_33.h"
#include <list>
#include <string>
#include<iostream>
using namespace std;

int main() {
    
    vectorQuene<int> v(10);
    v.enquene(1);
    cout << v.dequene() << v.full() << endl;
    cout << v.empty() << endl;
    return 0;
}