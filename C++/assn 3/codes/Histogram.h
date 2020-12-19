#pragma once
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#include <iostream>
using namespace std;

class Histogram {
    int numOfBins = 10; // stores the size of NormalizedFreq array i.e. (Nb as given in pdf)
    int N_s;
    double *intervals; // stores the bin values
    double *NormalizedFreq; // stores the bin NormalizedFreq

    public:
    Histogram();

    Histogram(const Histogram &hist); // copy constructor

    ~Histogram(); // destructor

    void setIntervals(int index, double value); // setter for a particular index in intervals
    void setFrequencies(int index, double value); // getter for a particular index in intervals
    double getFrequencies(int index); // getter for a particular index in NormalizedFreq

    // rounds of the number n to the pth decimal place
    double getIntervals(int index);
    void setNumOfBins(int n);
    int getNumOfBins();
    int getN_s();
    void setN_s(int n);
    void normalizeFrequencies();

    inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4; }

    // overloading "<<" operator using friend function
    friend void operator<<(Histogram &h, ostream& newcout){ 
        int i;
        newcout.precision(4);
        newcout << fixed;
        for(i=0; i<h.numOfBins; i++){
            newcout << h.truncfunc(h.intervals[i]) << ",";
        } newcout << h.truncfunc(h.intervals[i]) << " ";

        
        for(i=0; i<h.numOfBins-1; i++){
            newcout << h.truncfunc(h.NormalizedFreq[i]) << ",";
        } newcout << h.truncfunc(h.NormalizedFreq[i]) << " -1 ";
    }
};