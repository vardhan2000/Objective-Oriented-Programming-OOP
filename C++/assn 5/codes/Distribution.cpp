#include "Distribution.h"

Distribution::Distribution(){}
Distribution::~Distribution(){}

Distribution::Distribution(const Distribution &d): modes(d.modes) { // copy constructor
    mean = d.mean; 
    median = d.median;
    variance = d.variance;
}