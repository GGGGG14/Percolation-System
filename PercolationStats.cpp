#include <stdio.h>
#include <cstdlib>
#include "Percolation.hpp"
#include "PercolationStats.hpp"
#include <iostream>
#include <cmath>
using namespace std;

PercolationStats::PercolationStats(int N, int T) {
    
    NumberOfTests = T;
    
    if (N <= 0 or T <= 0) {
        cout << "Either N or T value(s) are out of range." << endl;
        error_code();
    }
    
    for (int i = 0; i < T; i++) {
        Results.push_back(RandomPercolation(N));
    }
}

double PercolationStats::mean() {
    
    double Sum = 0;
    
    for (int i = 0; i < Results.size(); i++) {
        Sum += Results[i];
    }
    
    return (Sum / Results.size());
}

double PercolationStats::stddev() {
    
    double Number = 0.0;
    
    for (int i = 0; i < Results.size(); i++) {
        Number += (Results[i] - mean()) * (Results[i] - mean());
    }
    
    return sqrt(1 / Results.size() * Number);
}

double PercolationStats::confidenceLow() {
    return ((mean() - (1.96 * stddev())) / sqrt(NumberOfTests));
}

double PercolationStats::confidenceHigh() {
    return ((mean() + (1.96 * stddev())) / sqrt(NumberOfTests));
}

PercolationStats::~PercolationStats() {
    Results.resize(0);
}

double PercolationStats::RandomPercolation(int N) {
    
    Percolation TestGrid(N);
    int OpenSites = 0;
    int RandomRow = 0;
    int RandomColumn = 0;
    
    while (!TestGrid.Percolates()) {
        
        do {
            RandomRow = (rand() % (N - 1));
            RandomColumn = (rand() % (N - 1));
        } while (TestGrid.IsOpen(RandomRow, RandomColumn));
        
        TestGrid.Open(RandomRow, RandomColumn);
        OpenSites++;
    }
    
    return (OpenSites / (N * N));
}
