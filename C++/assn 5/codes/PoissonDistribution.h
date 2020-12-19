#pragma once
#include "DiscreteDistribution.h"

class PoissonDistribution: public DiscreteDistribution{
    double m; // lambda
    
    public:
    PoissonDistribution(double m1): DiscreteDistribution(21){
        m = m1;
    }

    ~PoissonDistribution(){};

    PoissonDistribution(const PoissonDistribution &p): DiscreteDistribution(p){
        m = p.m;
    }

    bool isBinomial(){
        return false;
    }
    
    void compute_probDist();
    void descriptive_statistics();
    double computeMean(); 
    double computeMedian();
    void computeModes();
    double computeVariance();
    void expand(int);
};