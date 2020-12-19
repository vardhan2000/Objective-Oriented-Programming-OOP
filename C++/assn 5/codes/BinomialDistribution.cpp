#include "BinomialDistribution.h"
#include <cmath>

void BinomialDistribution::compute_probDist(){
    int r;
    double tem;
    for(r = 0; r < numOfBins; r++){
        
        tem = factorial(N)/(factorial(r) * factorial(N-r));
        tem *= pow(p,r) * pow(1-p,N-r);
        
        probDist[r].second = tem;
    }
}

void BinomialDistribution::descriptive_statistics(){
    mean = computeMean();
    variance = computeVariance();
    median = computeMedian();
    computeModes();
}

double BinomialDistribution::computeMean(){
    return N*p;
}

double BinomialDistribution::computeVariance(){
    return N*p*(1-p);
}

double BinomialDistribution::computeMedian(){
    return floor(N*p);
}

void BinomialDistribution::computeModes(){
    double t = (N+1)*p;
    if(t == 0 || floor(t) != t){
        modes.push_back(floor(t));
    } else if(t == N+1){
        modes.push_back(N);
    } else{
        modes.push_back(t-1);
        modes.push_back(t);
    }
}


