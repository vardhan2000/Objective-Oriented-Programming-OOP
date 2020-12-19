#include "BinomialDistribution.h"
#include <bits/stdc++.h>
#include<cmath>

void BinomialDistribution::makeHist(){
    int r, i;
    double tem;
    vector<double> temporary; // we'll NOT sort the binDis as it'll be used to compute 
                              // distances later on. So, we make its copy and store it in "temporary" vector
    
    /** computing the probability distribution **/
    for(r = 0; r < n+1; r++){
        // computing nCr 
        tem = factorial(n)/(factorial(r) * factorial(n-r));
        tem *= pow(p,r) * pow(1-p,n-r);
        
        // adding the computed nCr value to binDis and temporary vector
        add_to_binDis(tem);
        temporary.push_back(tem);
    }
    
    // sorting the temporary vector
    sort(temporary.begin(), temporary.end());

    /** computing the intervals and frequencies array **/
    double intervalSize, temp, minimum, maximum;
    minimum = temporary[0];
    maximum = temporary[n];
    if(minimum != maximum){
        intervalSize = (maximum-minimum) / (n+1); // intervalSize = size of each bin
        temp = minimum;
    } else { // if minimum = maximum(it actually includes the case of seq size being 1)
        intervalSize = 1.0/(n+1);
        temp = temporary[0]-0.5;
    }
    int index;

    // computing the bin values and storing them in intervals array of given histogram
    setIntervals(0,temp);
    for(i = 1; i <= (n+1); i++){
        temp += intervalSize;
        setIntervals(i, temp);
    }

    int t;
    for(i = 0; i < (n+1); i++){

        if(minimum != maximum){
            index = (temporary[i]-minimum)/intervalSize; // computing the index of the frequencies array of
                                               // given histogram, which needs to be updated for the
                                               // current sequence element
        } else { // if maximum = minimum
            index = (0.5)/intervalSize;
        }


        if(minimum == maximum || temporary[i] != maximum){
            t = getFrequencies(index) + 1;
            setFrequencies(index, t); 
        } else { // since the last bin excludes the maimum bin value
            t = getFrequencies(index-1) + 1;
            setFrequencies(index-1,t);
        }
    }
}