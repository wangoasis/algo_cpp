#include <iostream>
#include <stdlib.h>
#include "searchMaxSub.h"
#include <vector>

#define random(x) (rand()%100)
using std::cout; using std::endl;

int main() {
    vector<int> arr(20);
    for(int i=0;i<arr.size();i++)
        arr[i]=random(100)-50;
    
    searchMaxSub s = searchMaxSub();
    int maxSub=s.findMaxSub4(arr);
    for(int i=0;i<arr.size();i++)
        cout << arr[i] << ", ";
    cout << "\nmax subsequence is: " << maxSub << endl;

    return 0;
}
