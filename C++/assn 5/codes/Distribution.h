#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Distribution {

    protected:

    // if there are multiple medians, the "floor()" one is chosen
    double mean = -1, median = -1, variance = -1;
    vector<double> modes; // since there can be multiple modes
    int numOfBins;
    
    public:
    Distribution(); // constructor
    ~Distribution(); // destructor
    Distribution(const Distribution&); // copy constructor

    // pure virtual functions to compute mean, median, modes and variance
    virtual double computeMean(void) = 0; 
    virtual double computeMedian(void) = 0;
    virtual void computeModes() = 0;
    virtual double computeVariance(void) = 0;
};