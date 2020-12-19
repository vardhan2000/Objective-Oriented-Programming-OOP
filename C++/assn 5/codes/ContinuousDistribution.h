/*** There hasn't been ANYTHING done in this file. As told by Ma'am, I've copied
     and pasted the Histogram.h of Assn 3 JUST FOR THE SAKE OF COMPLETION ***/

#pragma once

#include "Distribution.h"
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>

class ContinuousDistribution: public Distribution {
    int numOfBins = 10; // stores the size of NormalizedFreq array i.e. (Nb as given in pdf)
    int N_s;
    double *intervals; // stores the bin values
    double *NormalizedFreq; // stores the bin NormalizedFreq

    public:
    ContinuousDistribution();

    ContinuousDistribution(const ContinuousDistribution &hist); // copy constructor

    ~ContinuousDistribution(); // destructor

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
    friend void operator<<(ContinuousDistribution &h, ostream& newcout){ 
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