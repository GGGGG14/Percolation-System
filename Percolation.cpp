#include "Percolation.hpp"
#include <vector>
using namespace std;

Percolation::Percolation(int N) {

    GridSize = N;
    Top = (GridSize * GridSize);
    Bottom = (Top + 1);
    
    int NumSites = N * N + 2;
    ConnectivityGrid = new WeightedQuickUnionUF(NumSites);
    
    vector<bool> BoolVector;
    
    for (int i = 0; i < GridSize; i++) { // create a vector of N size with false values
        BoolVector.push_back(false);
    }
    
    for (int i = 0; i < GridSize; i++) { // add that vector to the vector which holds bool vectors
        BoolGrid.push_back(BoolVector);
    }
    
    for (int i = 0; i < GridSize; i++) {
        ConnectivityGrid->unionize(ConvertTo1D(0, i), Top); // connect top row to top
        ConnectivityGrid->unionize(ConvertTo1D(GridSize - 1, i), Bottom); // connect bottom row to bottom
    }
}

void Percolation::Open(int Row, int Column) {
    
    BoolGrid[Row][Column] = true;
    
    if (ValidateIndex(Row - 1) and ValidateIndex(Column) and IsOpen(Row - 1, Column)) {
        ConnectivityGrid->unionize(ConvertTo1D(Row, Column), ConvertTo1D(Row - 1, Column));
    }
    
    if (ValidateIndex(Row) and ValidateIndex(Column + 1) and IsOpen(Row, Column + 1)) {
        ConnectivityGrid->unionize(ConvertTo1D(Row, Column), ConvertTo1D(Row, Column + 1));
    }
    
    if (ValidateIndex(Row + 1) and ValidateIndex(Column) and IsOpen(Row + 1, Column)) {
        ConnectivityGrid->unionize(ConvertTo1D(Row, Column), ConvertTo1D(Row + 1, Column));
    }
    
    if (ValidateIndex(Row) and ValidateIndex(Column - 1) and IsOpen(Row, Column - 1)) {
        ConnectivityGrid->unionize(ConvertTo1D(Row, Column), ConvertTo1D(Row, Column - 1));
    }
}

bool Percolation::IsOpen(int Row, int Column) {
    return (BoolGrid[Row][Column] == true);
}

bool Percolation::IsFull(int Row, int Column) {
    return (this->IsOpen(Row, Column) and ConnectivityGrid->connected(ConvertTo1D(Row, Column), Top));
}

int Percolation::NumberOfOpenSites() {
    
    int NumOpen = 0;
    
    for (int i = 0; i < GridSize; i++) {
        for (int j = 0; j < GridSize; j++) {
            if (BoolGrid[i][j] == true) {
                NumOpen += 1;
            }
        }
    }
    
    return NumOpen;
}

bool Percolation::Percolates() {
    return ConnectivityGrid->connected(Top, Bottom);
}

Percolation::~Percolation() {
    delete ConnectivityGrid;
    BoolGrid.resize(0);
}

int Percolation::ConvertTo1D(int Row, int Column) {
    return (GridSize * Row + Column);
}

bool Percolation::ValidateIndex(int Index) {
    return (Index >= 0 and Index < GridSize);
}
