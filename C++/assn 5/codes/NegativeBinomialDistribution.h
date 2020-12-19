#pragma once
#include "DiscreteDistribution.h"

class NegativeBinomialDistribution: public DiscreteDistribution{
    int r; // number of successes
    double p; // probability of success

    public:
    NegativeBinomialDistribution(int r1, double p1): DiscreteDistribution(21){
        r = r1;
        p = p1;
    }

    NegativeBinomialDistribution(const NegativeBinomialDistribution &n): DiscreteDistribution(n){
        r = n.r;
        p = n.p;
    }

    ~NegativeBinomialDistribution(){};

    bool isBinomial(){
        return false;
    }
    
    void compute_probDist();
    void descriptive_statistics();
    double computeMean(); 

    // since ther is NO formula for median of Negative binomial dist
    double computeMedian(){
        return -1;
    }
    void computeModes();
    double computeVariance();
    void expand(int);
};