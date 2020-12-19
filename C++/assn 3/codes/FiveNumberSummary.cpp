#include "FiveNumberSummary.h"
#include <cmath>

FiveNumberSummary::FiveNumberSummary(const FiveNumberSummary &f){ // copy constructor
    min = f.min;
    max = f.max;
    median = f.median;
    firstQuartile = f.firstQuartile;
    secondQuartile = f.secondQuartile;
}

void FiveNumberSummary::setMin(double val){
    min = val;
}

double FiveNumberSummary::getMin(){
    return min;
}

void FiveNumberSummary::setMax(double val){
    max = val;
}

double FiveNumberSummary::getMax(){
    return max;
}

void FiveNumberSummary::setMedian(double val){
    median = val;
}

void FiveNumberSummary::setFirstQuartile(double val){
    firstQuartile = val;
}

void FiveNumberSummary::setSecondQuartile(double val){
    secondQuartile = val;
}