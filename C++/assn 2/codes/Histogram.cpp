#include "Histogram.h"
#include <iomanip>
#include <iostream>
using namespace std;

Histogram::Histogram(const Histogram &hist){ // Copy constructor
    freSize = hist.freSize;
    intervals = new float[freSize+1];
    frequencies = new int[freSize];
    int i;
    for(i = 0; i < freSize; i++) {
        intervals[i] = hist.intervals[i];
        frequencies[i] = hist.frequencies[i];
    } 
    intervals[i] = hist.intervals[i];
}

void Histogram::printIntervals(){
    int i;
    cout.precision(4);
    cout << fixed;
    for(i = 0; i < freSize; i++){
        cout << truncfunc(intervals[i])  << ",";
    } cout << truncfunc(intervals[i]);
}

void Histogram::printFrequencies(){
    int i;
    for(i = 0; i < freSize-1; i++){
        cout << frequencies[i] << ",";
    } cout << frequencies[i];
}