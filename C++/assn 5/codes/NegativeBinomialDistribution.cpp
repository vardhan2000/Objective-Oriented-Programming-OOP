#include "NegativeBinomialDistribution.h"
#include <cmath>

void NegativeBinomialDistribution::compute_probDist(){
    int k;
    double tem;
    for(k = 0; k < numOfBins; k++){
        tem = factorial(k+r-1)/(factorial(r-1) * factorial(k));
        tem *= pow(p,r) * pow(1-p,k);
        
        probDist[k].second = tem;
    }
}

void NegativeBinomialDistribution::descriptive_statistics(){
    mean = computeMean();
    variance = computeVariance();
    computeModes();
    median = computeMedian();
}

void NegativeBinomialDistribution::expand(int n){
    int begin = probDist.size(), k;
    if(n <= begin) { return; }

    double tem;
    for(k = begin; k < n; k++){
        tem = factorial(k+r-1)/(factorial(r-1) * factorial(k));
        tem *= pow(p,r) * pow(1-p,k);

        probDist.push_back(make_pair(to_string(k), tem));
    }
}

double NegativeBinomialDistribution::computeMean(){
    return (p*r)/(1-p);
}

double NegativeBinomialDistribution::computeVariance(){
    return (p*r)/pow(1-p,2);
}

void NegativeBinomialDistribution::computeModes(){
    if(r > 1){
        modes.push_back(floor((p*(r-1))/(1-p)));
    } else {
        modes.push_back(0);
    }
}
