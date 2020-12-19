#include "Histogram.h"
#include <iomanip>
#include <iostream>
using namespace std;

Histogram::Histogram(){
    intervals = new double[numOfBins+1];
    NormalizedFreq = new double[numOfBins];
}

Histogram::Histogram(const Histogram &h){ // Copy constructor
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

Histogram::~Histogram(){
    delete[] intervals;
    delete[] NormalizedFreq;
}

void Histogram::setIntervals(int index, double value){ // setter for a particular index in intervals
        intervals[index] = value;
    }

void Histogram::setFrequencies(int index, double value){ // getter for a particular index in intervals
    NormalizedFreq[index] = value;
}

double Histogram::getFrequencies(int index){ // getter for a particular index in NormalizedFreq
    return NormalizedFreq[index];
}

double Histogram::getIntervals(int index){
    return intervals[index];
}

void Histogram::setNumOfBins(int n){
    numOfBins = n;
}

int Histogram::getNumOfBins(){
    return numOfBins;
}

int Histogram::getN_s(){
    return N_s;
}

void Histogram::setN_s(int n){
    N_s = n;
}

void Histogram::normalizeFrequencies(){
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