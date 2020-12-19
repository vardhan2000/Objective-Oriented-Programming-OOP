#pragma once

#include "Distribution.h"
#include <string>
#include <vector>
#include <cmath>

class DiscreteDistribution: public Distribution {
    protected:

    // probability distribution vector with label-value pairs
    vector<pair <string, double> > probDist;

    // used to calculate KL_distance and JS_distance
    double KL_divergence(vector<pair<string, double>>&, vector<pair<string, double>>&, int);

    int Limit(DiscreteDistribution&, DiscreteDistribution&);
    
    public:
    DiscreteDistribution(int n): Distribution() {
        numOfBins = n;
        int i;

        // putting up the bin-labels like "0", "1", "2"..., "n"
        // as mentioned in the pdf
        for(i = 0; i < n; i++){
            probDist.push_back(make_pair(to_string(i), 0));
        }
    }

    ~DiscreteDistribution(){};

    // copy Constructor
    DiscreteDistribution(const DiscreteDistribution &d): Distribution(d), probDist(d.probDist){}

    inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

    // recursive function to compute factorial
    double factorial(int n) { 
        if(n==1 || n==0){
            return 1;
        } 
        return n * factorial(n - 1);  
    }

    // friend function to overload the std::cout function to print 
    // out its descriptive statistics
    friend void operator<<(DiscreteDistribution&, ostream&);
    
    
    // virtual functions that will be used to to:
    // 1. compute probability distribution array
    // 2. compute descriptive statistics
    // 3. expand a discrete distribution(ONLY IF it has infinite support)
    virtual void compute_probDist(void) = 0;
    virtual void descriptive_statistics(void) = 0;
    virtual void expand(int) = 0;
    
    // to check if the current object is BinomialDistribution or NOT
    virtual bool isBinomial() = 0;

    // 5 friend functions for 5 different distances
    friend double ManhattanDistance(DiscreteDistribution&, DiscreteDistribution&);
    friend double EuclideanDistance(DiscreteDistribution&, DiscreteDistribution&);
    friend double Chebyshev_distance(DiscreteDistribution&, DiscreteDistribution&);
    friend double KL_distance(DiscreteDistribution&, DiscreteDistribution&);
    friend double JS_distance(DiscreteDistribution&, DiscreteDistribution&);

    // calls one of the 5 distance functions A/T the distance code provided as
    // a character array. 
    friend double computeDist(char arr[], DiscreteDistribution&, DiscreteDistribution&);
};