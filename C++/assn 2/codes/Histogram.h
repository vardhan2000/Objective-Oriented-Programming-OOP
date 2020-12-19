#pragma once
#include<bits/stdc++.h>
#include<cmath>

class Histogram {
    float *intervals; // stores the bin values
    int *frequencies; // stores the bin frequencies
    int freSize; // stores the size of frequencies array

    public:
    Histogram(int freqSize){ // Constructor
        intervals = new float[freqSize+1];
        frequencies = new int[freqSize];
        freSize = freqSize;
    }

    Histogram(const Histogram &hist); // copy constructor

    ~Histogram(){ // destructor
        delete[] intervals;
        delete[] frequencies;
    }

    void setIntervals(int index, float value){ // setter for a particular index in intervals
        intervals[index] = value;
    }

    void setFrequencies(int index, int value){ // getter for a particular index in intervals
        frequencies[index] = value;
    }

    int getFrequencies(int index){ // getter for a particular index in frequencies
        return frequencies[index];
    }

    inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

    void printIntervals(); // prints the bin values seperated with commas
    void printFrequencies(); // prints the bin frequencies seperated with commas
};