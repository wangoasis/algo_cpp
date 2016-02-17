#ifndef matrix_H
#define matrix_H

#include <vector>
#include <iostream>
using std::vector;

template <typename Object>

class matrix {
public:
    matrix(int rows, int cols):array(rows) {
        for(int i=0;i<rows;i++)
            array[i].resize(cols);
    }
    
    const vector<Object> & operator [] (int row) const {
        return array[row];
    }

    vector<Object> & operator [] (int row) {
        return array[row];
    }

    int numRows() const {
        return array.size();
    }

    int numCols() const {
        return numRows() ? array[0].size() : 0;
    }

    void fullPrint() const {
        for(int i=0;i<numRows();i++) {
            for(int j=0;j<numCols();j++)
                std::cout << "\t" << array[i][j] << "\t";
            std::cout << std::endl;
        }
    }

    void halfPrint() const {
        for(int i=0;i<numRows();i++) {
            for(int j=0;j<=i;j++)
                std::cout << "\t" << array[i][j] << "\t";
            std::cout << std::endl;
        }
    }

private:
    vector<vector<Object>> array;
};

#endif
