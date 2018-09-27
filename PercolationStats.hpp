#ifndef PercolationStats_hpp
#define PercolationStats_hpp

#include <vector>
using namespace std;

class PercolationStats {

    public:
        PercolationStats(int N, int T);   // perform T independent experiments on an N-by-N grid
        double mean();                    // sample mean of percolation threshold
        double stddev();                  // sample standard deviation of percolation threshold
        double confidenceLow();           // low  endpoint of 95% confidence interval
        double confidenceHigh();          // high endpoint of 95% confidence interval
        ~PercolationStats();              // destructor
    
    private:
        vector<double> Results;
        double RandomPercolation(int N);
        int NumberOfTests;
};

#endif /* PercolationStats_h */
