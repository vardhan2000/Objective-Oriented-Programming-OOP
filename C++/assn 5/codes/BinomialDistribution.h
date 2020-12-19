#pragma once
#include "DiscreteDistribution.h"

class BinomialDistribution: public DiscreteDistribution{
    int N; // number of trials
    double p; // probability of success

    public:
    BinomialDistribution(int n, double p1): DiscreteDistribution(n){
        N = n;
        p = p1;
    }

    BinomialDistribution(const BinomialDistribution &b): DiscreteDistribution(b){
        N = b.N;
        p = b.p;
    }

    ~BinomialDistribution(){};

    bool isBinomial(){
        return true;
    }

    // it does NOTHING since binomial distribution is a finite support
    // distribution
    void expand(int n){
        return;
    }
    
    void compute_probDist();
    void descriptive_statistics();
    double computeMean(); 
    double computeMedian();
    void computeModes();
    double computeVariance();
};