#include "Histogram.h"
#include <iostream>
#include <cmath>
using namespace std;

Histogram::Histogram(const Histogram &h){
    freSize = h.freSize;
    intervals = new double[freSize+1];
    frequencies = new int[freSize];

    int i;
    for(i = 0; i < freSize; i++){
        intervals[i] = h.intervals[i];
        frequencies[i] = h.frequencies[i];
    } intervals[i] = h.intervals[i];

    int limit = h.binDis.size();
    for(i = 0; i < limit; i++){
        binDis.push_back(h.binDis[i]);
    }
}

//returns the Manhattan distance for given histograms
double ManhattanDistance(Histogram &h1, Histogram &h2, int size)  {
    if(h1.freSize != h2.freSize){
        cerr << "-1 ";
        return -1;
    }

    double distance = 0;
    int i;
    for(i=0; i<size; i++){
        distance +=  fabs(h1.binDis[i]-h2.binDis[i]);
    } return distance;
}

//returns the Euclidean distance for given histograms
double EuclideanDistance(Histogram &h1, Histogram &h2, int size)  {
    if(h1.freSize != h2.freSize){
        cerr << "-1 ";
        return -1;
    }

    double distanceSquare = 0, distance;
    int i;
    for(i=0; i<size; i++){
        distanceSquare += pow(h1.binDis[i]-h2.binDis[i], 2);
    } distance = sqrt(distanceSquare);

    return distance;
}

//returns the Chebyshev distance for given histograms
double Chebyshev_distance(Histogram &h1, Histogram &h2, int size)  {
    if(h1.freSize != h2.freSize){
        cerr << "-1 ";
        return -1;
    }

    double distance = 0;
    int i;
    for(i=0; i<size; i++){
        if(distance < fabs(h1.binDis[i]-h2.binDis[i])){
            distance = fabs(h1.binDis[i]-h2.binDis[i]);
        }
    } return distance;
}

//returns the KL divergence for given histograms
double Histogram::KL_divergence(vector<double> &v1, vector<double> &v2, int size)  {
    double kl_divergence=0;
    int i;
    for(i=0; i<size; i++){
        kl_divergence += (v1[i] * log(v1[i]/v2[i]));
    } return kl_divergence;
}


double KL_distance(Histogram &h1, Histogram &h2, int size){
    if(h1.freSize != h2.freSize){
        cerr << "-1 ";
        return -1;
    }

    return h1.KL_divergence(h1.binDis, h2.binDis, size) + h1.KL_divergence(h2.binDis, h1.binDis, size);
}

//returns the JS distance for given histograms
double JS_distance(Histogram &h1, Histogram &h2, int size)  {
    if(h1.freSize != h2.freSize){
        cerr << "-1 ";
        return -1;
    }

    double js_divergence, js_distance;
    vector<double> median;
    int i;

    //making the median vector
    for(i=0; i<size; i++){
        median.push_back((h1.binDis[i]+h2.binDis[i])/2);
    }

    js_divergence = (0.5 * h1.KL_divergence(h1.binDis,median,size))+(0.5 * h1.KL_divergence(h2.binDis,median,size));
    js_distance = sqrt(js_divergence);//NOTE that JS distance is the squre root of the JS divergence
    return js_distance;
}