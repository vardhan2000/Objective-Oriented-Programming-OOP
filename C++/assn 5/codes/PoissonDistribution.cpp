#include "PoissonDistribution.h"
#include <cmath>

void PoissonDistribution::compute_probDist(){
    int k;
    double tem;
    for(k = 0; k < numOfBins; k++){
        tem = (pow(m,k)*exp(-m))/factorial(k);
        
        probDist[k].second = tem;
    }
}

void PoissonDistribution::descriptive_statistics(){
    mean = computeMean();
    variance = computeVariance();
    computeModes();
    median = computeMedian();
}

void PoissonDistribution::expand(int n){
    int begin = probDist.size(), k;
    if(n <= begin) { return; }

    double tem;
    for(k = begin; k < n; k++){
        tem = (pow(m,k)*exp(-m))/factorial(k);

        probDist.push_back(make_pair(to_string(k), tem));
    }
}

double PoissonDistribution::computeMean(){
    return m;
}

double PoissonDistribution::computeVariance(){
    return m;
}

void PoissonDistribution::computeModes(){
    if(ceil(m)-1 != floor(m)){
        modes.push_back(ceil(m)-1);
        modes.push_back(floor(m));
    } else {
        modes.push_back(floor(m));
    }
    
}

double PoissonDistribution::computeMedian(){
    return floor(m + (1/3) - (0.02/m));
}