#ifndef Percolation_hpp
#define Percolation_hpp

#include <stdio.h>
#include <vector>
#include "WeightedQuickUnionUF.hpp"
using namespace std;

class Percolation {
    
public:
    Percolation(int N);
    void Open(int Row, int Column);
    bool IsOpen(int Row, int Column);
    bool IsFull(int Row, int Column);
    int NumberOfOpenSites();
    bool Percolates();
    ~Percolation();
    
private:
    int GridSize;
    int Top;
    int Bottom;
    WeightedQuickUnionUF *ConnectivityGrid;
    vector<vector<bool>> BoolGrid;
    int ConvertTo1D(int Row, int Column);
    bool ValidateIndex(int Index);
};

#endif
