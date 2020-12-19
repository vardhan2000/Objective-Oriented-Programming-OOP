#include <iostream>
#include "DataSequence.h"

void DataSequence::merge(int l, int m, int r){
    int size1, size2; // stores the size of the temporary left[] and right[] arrays
    size1 = m-l+1;
    size2 = r-m;

    float *left = new float[size1]; 
    float *right = new float[size2];

    int i, j;
    for(i = 0; i < size1; i++){
        left[i] = seq[l+i];
    }

    for(j = 0; j < size2; j++){
        right[j] = seq[m+1+j];
    }

    int k = l;
    i = 0; j = 0;
    while(i < size1 && j < size2){
        if(left[i] <= right[j]){
            seq[k] = left[i];
            i++;
        } else {
            seq[k] = right[j];
            j++;
        } k++;
    }

    while(i < size1){ 
        seq[k] = left[i]; 
        i++; k++; 
    }

    while(j < size2){
        seq[k] = right[j];
        j++; k++;
    }
}

void DataSequence::mergeSort(int l, int r) {
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

void DataSequence::sort(){
    mergeSort(0,seqSize-1);
}

float DataSequence::min(){
    minimum = seq[0]; // since we are dealing with a sorted sequence
    return minimum;
}

float DataSequence::mean(){
    int i;
    float sum = 0;
    for(i = 0; i < seqSize; i++){
        sum += seq[i];
    } return sum/seqSize;
}

float DataSequence::max(){
    maximum = seq[seqSize-1]; // since we are dealing with a sorted sequence
    return maximum;
}

float DataSequence::median(){
    int index;
    if(seqSize % 2 != 0){ // if size of sequence is odd
        index = (seqSize + 1) / 2; 
        return seq[index-1];
    } else { // if size of sequence is even
        index = seqSize / 2;
        return (seq[index-1] + seq[index]) / 2;
    }
}

DataSequence::DataSequence(const DataSequence &s){ // Copy constructor
        seqSize = s.seqSize;
        
        seq = new float[seqSize];
        for(int i = 0; i < seqSize; i++){
            seq[i] = s.seq[i];
        }

        num_of_bins = s.num_of_bins;
        minimum = s.minimum;
        maximum = s.maximum;
    }

void DataSequence::buildHistogram(Histogram &h){
    float intervalSize, temp;

    if(minimum != maximum){
        intervalSize = (maximum-minimum) / num_of_bins; // intervalSize = size of each bin
        temp = minimum;
    } else { // if minimum = maximum(it actually includes the case of seq size being 1)
        intervalSize = 1.0/num_of_bins;
        temp = seq[0]-0.5;
    }
    int i, index;

    // computing the bin values and storing them in intervals array of given histogram
    h.setIntervals(0,temp);
    for(i = 1; i <= num_of_bins; i++){
        temp += intervalSize;
        h.setIntervals(i, temp);
    }

    int t;
    for(i = 0; i < seqSize; i++){

        if(minimum != maximum){
            index = (seq[i]-minimum)/intervalSize; // computing the index of the frequencies array of
                                               // given histogram, which needs to be updated for the
                                               // current sequence element
        } else { // if maximum = minimum
            index = (0.5)/intervalSize;
        }


        if(minimum == maximum || seq[i] != maximum){
            t = h.getFrequencies(index) + 1;
            h.setFrequencies(index, t); 
        } else { // since the last bin excludes the maimum bin value
            t = h.getFrequencies(index-1) + 1;
            h.setFrequencies(index-1,t);
        }
    }
}