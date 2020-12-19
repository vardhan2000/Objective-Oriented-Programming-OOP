/*** There hasn't been ANYTHING done in this file. As told by Ma'am, I've copied
     and pasted the Histogram.cpp of Assn 3 JUST FOR THE SAKE OF COMPLETION ***/

#include "ContinuousDistribution.h"

ContinuousDistribution::ContinuousDistribution(){
    intervals = new double[numOfBins+1];
    NormalizedFreq = new double[numOfBins];
}

ContinuousDistribution::ContinuousDistribution(const ContinuousDistribution &h){ // Copy constructor
    numOfBins = h.numOfBins;
    intervals = new double[numOfBins+1];
    NormalizedFreq = new double[numOfBins];
    int i;
    for(i = 0; i < numOfBins; i++){
        intervals[i] = h.intervals[i];
        NormalizedFreq[i] = h.NormalizedFreq[i];
    } 
    intervals[i] = h.intervals[i];
}

ContinuousDistribution::~ContinuousDistribution(){
    delete[] intervals;
    delete[] NormalizedFreq;
}

void ContinuousDistribution::setIntervals(int index, double value){ // setter for a particular index in intervals
        intervals[index] = value;
    }

void ContinuousDistribution::setFrequencies(int index, double value){ // getter for a particular index in intervals
    NormalizedFreq[index] = value;
}

double ContinuousDistribution::getFrequencies(int index){ // getter for a particular index in NormalizedFreq
    return NormalizedFreq[index];
}

double ContinuousDistribution::getIntervals(int index){
    return intervals[index];
}

void ContinuousDistribution::setNumOfBins(int n){
    numOfBins = n;
}

int ContinuousDistribution::getNumOfBins(){
    return numOfBins;
}

int ContinuousDistribution::getN_s(){
    return N_s;
}

void ContinuousDistribution::setN_s(int n){
    N_s = n;
}

void ContinuousDistribution::normalizeFrequencies(){
    int i;
    double a;
    for(i=0; i<numOfBins; i++){
        a = NormalizedFreq[i];
        if(a!=0){
            a = a/N_s;
            NormalizedFreq[i] = a;
        }
    }
}