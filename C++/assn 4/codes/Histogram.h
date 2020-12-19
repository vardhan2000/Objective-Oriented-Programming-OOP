#pragma once
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Histogram {
    int freSize; // stores the size of frequencies array i.e. equal to number of bins
    double *intervals; // stores the bin values
    int *frequencies; // stores the bin frequencies
    vector<double> binDis; // stores the probability distribution

    
    // declaring the private function (so that it is explicitly used by the Histogram class
    // and NOT by its derived class) to compute KL_divergence which will be used by:-
    // 1. KL_distance()
    // 2. JS_distance()
    double KL_divergence(vector<double>&, vector<double>&, int);

    public:
    Histogram(int freqSize){ // Constructor
        freSize = freqSize;
        intervals = new double[freqSize+1];
        frequencies = new int[freqSize];
    }

    ~Histogram(){ // destructor
        delete[] intervals;
        delete[] frequencies;
    }

    Histogram(const Histogram&); // copy constructor

    void setIntervals(int index, double value){ // setter for a particular index in intervals
        intervals[index] = value;
    }

    void setFrequencies(int index, int value){ // getter for a particular index in intervals
        frequencies[index] = value;
    }

    int getFrequencies(int index){ // getter for a particular index in frequencies
        return frequencies[index];
    }

    void add_to_binDis(double x){
        binDis.push_back(x);
    }

    double getBinDis(int index){
        return binDis[index];
    }

    // 5 friend functions for 5 different distances
    friend double ManhattanDistance(Histogram&, Histogram&, int size);
    friend double EuclideanDistance(Histogram&, Histogram&, int size);
    friend double Chebyshev_distance(Histogram&, Histogram&, int size);
    friend double KL_distance(Histogram&, Histogram&, int size);
    friend double JS_distance(Histogram&, Histogram&, int size);
};