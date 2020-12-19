#pragma once
#include "Histogram.h"

class DataSequence{
    float *seq; // stores the sequence
    int seqSize, num_of_bins;
    float minimum, maximum; // stores the minimum and maximum values of the sequence

    public:
    DataSequence(int size){ // Constructor 
        seqSize = size;
        seq = new float[size];
    }

    DataSequence(const DataSequence &s); // copy constructor

    ~DataSequence(){ // destructor
        delete[] seq;
    }

    void setSeq(float value, int index){ // setter for a particular index in seq
        seq[index] = value;
    }

    float getSeq(int index){ // getter for a particular index in seq
        return seq[index];
    }

    void setNum_of_bins(int n){ // setter for "num_of_bins" field
        num_of_bins = n;
    }

    // merge and merge sort functions
    void merge(int l, int m, int r);  
    void mergeSort(int l, int r);

    void sort(); // calls the merge sort function by assigning l,r arguments
    
    // NOTE that these methods will be called only after the sequence has been sorted
    float min(); float mean();
    float median(); float max();

    // 1. computes and stores the bin values in intervals array of the given histogram
    // 2. computes and stores the bin frequencies in frequencies array of the given histogram
    void buildHistogram(Histogram &h); // NOTE that we pass the "reference" of the histogram
};