#pragma once
#include "Histogram.h"
#include "FiveNumberSummary.h"
#include <vector>
#include<iostream>
using namespace std;

class DataSequence{
    vector<double> sequence; // stores the sequence
    Histogram &hist;
    FiveNumberSummary fiveNumSum;

    public:
    DataSequence(Histogram &h): hist(h), fiveNumSum(){} // Constructor

    DataSequence(const DataSequence &s); // copy constructor

    ~DataSequence(){} // destructor


    // Note that "each time" an element is added, the histogram,
    // sequence and fiveNumberSummary gets updated
    void addElement(double value);

    double getSeq(int index){ // getter for a particular index in seq
        return sequence[index];
    }

    // merge and merge sort functions
    void merge(int l, int m, int r);  
    void mergeSort(int l, int r);

    void sort(); // calls the merge sort function by assigning l,r arguments
    
    // NOTE that these methods will be called only after the sequence has been sorted
    void min();
    double med(int l, int r); void max();
    double quartile(int n); // returns nth quartile of sequence 


    // 1. computes and stores the bin values in intervals array of the given histogram
    // 2. computes and stores the bin NormalizedFreq in NormalizedFreq array of the given histogram
    void buildHistogram(); // NOTE that we pass the "reference" of the histogram
    void normalize();

    // overloading "<<" operator using friend function
    friend void operator<<(DataSequence &d, ostream& newcout){
        d.fiveNumSum << cout;
        d.hist << cout;

    }
};