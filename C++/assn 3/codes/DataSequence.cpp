#include <iostream>
#include "DataSequence.h"

DataSequence::DataSequence(const DataSequence &s): hist(s.hist), fiveNumSum(s.fiveNumSum){ // Copy constructor
    for(double e: s.sequence){
        sequence.push_back(e);
    }
}


void DataSequence::merge(int l, int m, int r){
    int size1, size2; // stores the size of the temporary left[] and right[] arrays
    size1 = m-l+1;
    size2 = r-m;

    double *left = new double[size1]; 
    double *right = new double[size2];

    int i, j;
    for(i = 0; i < size1; i++){
        left[i] = sequence[l+i];
    }

    for(j = 0; j < size2; j++){
        right[j] = sequence[m+1+j];
    }

    int k = l;
    i = 0; j = 0;
    while(i < size1 && j < size2){
        if(left[i] <= right[j]){
            sequence[k] = left[i];
            i++;
        } else {
            sequence[k] = right[j];
            j++;
        } k++;
    }

    while(i < size1){ 
        sequence[k] = left[i]; 
        i++; k++; 
    }

    while(j < size2){
        sequence[k] = right[j];
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
    mergeSort(0,sequence.size()-1);
}

void DataSequence::addElement(double e){
    sequence.push_back(e);
    this->sort();
    this->min();
    this->max();
    this->fiveNumSum.setMedian(this->quartile(2));
    this->fiveNumSum.setFirstQuartile(this->quartile(1));
    this->fiveNumSum.setSecondQuartile(this->quartile(3));
    this->hist.setN_s(this->hist.getN_s()+1);
    this->buildHistogram();
}

void DataSequence::min(){
    fiveNumSum.setMin(sequence[0]); // since we are dealing with a sorted sequence
}

void DataSequence::max(){
    fiveNumSum.setMax(sequence[sequence.size()-1]); // since we are dealing with a sorted sequence
}

double DataSequence::quartile(int n){
    double p = n/4.0, temp;
    temp = p*(sequence.size()-1);
    int index1, index2;
    index1 = floor(temp);
    index2 = ceil(temp);
    return 0.5*(sequence[index1]+sequence[index2]);
}

void DataSequence::normalize(){
    this->hist.normalizeFrequencies();
}

void DataSequence::buildHistogram(){
    double intervalSize, temp;

    if(fiveNumSum.getMin() != fiveNumSum.getMax()){
        intervalSize = (fiveNumSum.getMax()-fiveNumSum.getMin()) / hist.getNumOfBins(); // intervalSize = size of each bin
        temp = fiveNumSum.getMin();
    } else { // if minimum = maximum(it actually includes the case of seq size being 1)
        intervalSize = 1.0/hist.getNumOfBins();
        temp = sequence[0]-0.5;
    }
    int i, index;

    // computing the bin values and storing them in intervals array of given histogram
    hist.setIntervals(0,temp);
    for(i = 1; i <= hist.getNumOfBins(); i++){
        temp += intervalSize;
        hist.setIntervals(i, temp);
        hist.setFrequencies(i-1,0);
    }

    double t;
    int limit = sequence.size();
    for(i = 0; i < limit; i++){

        if(fiveNumSum.getMin() != fiveNumSum.getMax()){
            index = (sequence[i]-fiveNumSum.getMin())/intervalSize; // computing the index of the NormalizedFreq array of
                                               // given histogram, which needs to be updated for the
                                               // current sequence element
        } else { // if maximum = minimum
            index = (0.5)/intervalSize;
        }


        if(fiveNumSum.getMin() == fiveNumSum.getMax() || sequence[i] != fiveNumSum.getMax()){
            t = hist.getFrequencies(index) + 1;
            hist.setFrequencies(index, t); 
        } else { // since the last bin excludes the maimum bin value
            t = hist.getFrequencies(index-1) + 1;
            hist.setFrequencies(index-1,t);
        }
    }
}