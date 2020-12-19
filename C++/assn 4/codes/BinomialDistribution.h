#pragma once
#include "Histogram.h"

class BinomialDistribution: public Histogram{
    int n;
    double p;

    public:
    BinomialDistribution(int n1, double p1):Histogram(n1+1){ // constructor
        n = n1;
        p = p1;
    }

    ~BinomialDistribution(){}; // destructor

    BinomialDistribution(const BinomialDistribution &b):Histogram(b){ // copy constructor
        n = b.n;
        p = b.p;
    }

    // recursive function to compute factorial
    double factorial(int n) { 
        if(n==1 || n==0){
            return 1;
        } 
        return n * factorial(n - 1);  
    }

    // calling the makeHist() method to compute the:-
    // 1. probability distribution array(which will act as a sequence to construct the histograms)
    // 2. intervals array(bin-values)
    // 3. frequency array
    void makeHist();
};