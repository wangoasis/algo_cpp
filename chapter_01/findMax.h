#ifndef findMax_H
#define findMax_H

#include <string> 
using std::string;
#include <vector>
using std::vector;

#include <algorithm>
#include <cctype>

//generic findMax function, with a function object
template<typename Object, typename Comparator>
const Object & findMax (const vector<Object> & arr, Comparator isLessThan) {
    int maxIndex = 0;
    for(int i=1;i<arr.size();i++) {
        if(isLessThan(arr[maxIndex],arr[i]))
        //isLessThan is a function object, which has realized the operator ()
            maxIndex=i;
    }
    
    return arr[maxIndex];
}

//generic findMax, using default ordering
#include<functional>
template<typename Object>
const Object & findMax(const vector<Object> & arr) {
    return findMax(arr,std::less<Object>());
}

//to build a function object
class CaseInsensitiveCompare
{
public:
    bool operator () (const string & lhs, const string & rhs) const {
        return lhs < rhs;
    }
};

//to build a function object
class CaseUninsensitiveCompare
{
public:
    bool operator () (const string & lhs, const string & rhs) const {
        string left, right;
        // transform to lower case
        transform(lhs.begin(), lhs.end(), back_inserter(left), tolower);
        transform(rhs.begin(), rhs.end(), back_inserter(right), tolower);
        return left < right;
    }
};
#endif
