#include "findMax.h"
#include <iostream>
#include <string>


int main () {
    vector<string> arr{ "ZEVRA", "alligator", "crocodile" };
    for(auto &s : arr)
        std::cout << s << " ";
    std::cout << std::endl;
    std::cout << "case intensive " << findMax(arr,CaseInsensitiveCompare()) << std::endl;
    std::cout << "case unintensive " << findMax(arr,CaseUninsensitiveCompare()) << std::endl;
    std::cout << "standard comparision " << findMax(arr) << std::endl;
}
