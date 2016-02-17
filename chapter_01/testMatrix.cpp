#include "matrix.h"

int main() {
    
    matrix<int> m(9,9);
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            m[i-1][j-1] = i * j;
    m.halfPrint();   
}
