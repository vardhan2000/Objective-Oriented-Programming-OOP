#include "DiscreteDistribution.h"
#include <cmath>
#include <cstring>

//returns the Manhattan distance for given DiscreteDistributions
double ManhattanDistance(DiscreteDistribution &d1, DiscreteDistribution &d2)  {
    int limit = d1.Limit(d1, d2);

    if(limit == -1) { return -1; }

    double distance = 0;
    int i;
    for(i=0; i<limit; i++){
        distance +=  fabs(d1.probDist[i].second-d2.probDist[i].second);
    } return distance;
}

//returns the Euclidean distance for given DiscreteDistributions
double EuclideanDistance(DiscreteDistribution &d1, DiscreteDistribution &d2)  {
    int limit = d1.Limit(d1, d2);

    if(limit == -1) { return -1; }

    double distanceSquare = 0, distance;
    int i;
    for(i=0; i<limit; i++){
        distanceSquare += pow(d1.probDist[i].second-d2.probDist[i].second, 2);
    } distance = sqrt(distanceSquare);

    return distance;
}

//returns the Chebyshev distance for given DiscreteDistributions
double Chebyshev_distance(DiscreteDistribution &d1, DiscreteDistribution &d2)  {
    int limit = d1.Limit(d1, d2);

    if(limit == -1) { return -1; }

    double distance = 0;
    int i;
    for(i=0; i<limit; i++){
        if(distance < fabs(d1.probDist[i].second-d2.probDist[i].second)){
            distance = fabs(d1.probDist[i].second-d2.probDist[i].second);
        }
    } return distance;
}

//returns the KL divergence for given DiscreteDistributions
double DiscreteDistribution::KL_divergence(vector<pair<string, double>> &v1, vector<pair<string, double>> &v2, int limit){
    double kl_divergence=0;
    int i;
    for(i=0; i<limit; i++){
        kl_divergence += (v1[i].second * log(v1[i].second/v2[i].second));
    } return kl_divergence;
}


double KL_distance(DiscreteDistribution &d1, DiscreteDistribution &d2){
    int limit = d1.Limit(d1, d2);

    if(limit == -1) { return -1; }

    return d1.KL_divergence(d1.probDist, d2.probDist, limit) + d1.KL_divergence(d2.probDist, d1.probDist, limit);
}

//returns the JS distance for given DiscreteDistributions
double JS_distance(DiscreteDistribution &d1, DiscreteDistribution &d2)  {
    int limit = d1.Limit(d1, d2);

    if(limit == -1) { return -1; }

    double js_divergence, js_distance, temp;
    vector<pair<string, double>> median;
    int i;
    
    //making the median vector
    for(i=0; i<limit; i++){
        temp = (d1.probDist[i].second+d2.probDist[i].second)/2;
        median.push_back(make_pair(d1.probDist[i].first, temp));
    }

    js_divergence = (0.5 * d1.KL_divergence(d1.probDist,median,limit))+(0.5 * d1.KL_divergence(d2.probDist,median,limit));
    js_distance = sqrt(js_divergence);//NOTE that JS distance is the squre root of the JS divergence
    return js_distance;
}

double computeDist(char arr[], DiscreteDistribution &d1, DiscreteDistribution&d2){
    if(strcmp(arr, "D1") == 0){
        return ManhattanDistance(d1,d2);
    } else if(strcmp(arr, "D2") == 0) {
        return EuclideanDistance(d1,d2);
    } else if(strcmp(arr, "D3") == 0) {
        return Chebyshev_distance(d1,d2);
    } else if(strcmp(arr, "D4") == 0) {
        return KL_distance(d1,d2);
    } else {
        return JS_distance(d1,d2);
    } 
}

// calculates the upper limit for iteration through the probability distribution
// array while calculating distances
int DiscreteDistribution::Limit(DiscreteDistribution &d1, DiscreteDistribution &d2){
    int t1, t2, limit;
    t1 = d1.probDist.size();
    t2 = d2.probDist.size();
    if(d1.isBinomial() && d2.isBinomial()){
        if(t1 != t2) { return -1; }
        limit = t1;
    } else if (!d1.isBinomial() && !d2.isBinomial()){
        if(t1 > t2){
            limit = t2;
        } else {
            limit = t1;
        }
    } else {
        if(d1.isBinomial()){
            limit = t1;
            if(t1 > t2){
                d2.expand(t1);
            } 
        } else {
            limit = t2;
            if(t2 > t1){
                d1.expand(t2);
            }
        }
    } return limit;
}

void operator<<(DiscreteDistribution& d, ostream& newcout){
    newcout << fixed;
    newcout.precision(4);
    if(d.median != -1){
        newcout << d.truncfunc(d.mean) << "," << d.truncfunc(d.median) << ",";
        for(double x: d.modes){
            newcout << d.truncfunc(x) << ",";
        }
        newcout << d.truncfunc(d.variance);
    } else {
        newcout << d.truncfunc(d.mean) << ",";
        for(double x: d.modes){
            newcout << d.truncfunc(x) << ",";
        }
        newcout << d.truncfunc(d.variance);
    }
}