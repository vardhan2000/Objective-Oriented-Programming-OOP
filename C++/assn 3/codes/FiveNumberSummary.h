#pragma once

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class FiveNumberSummary {
    double min, max, median;
    double firstQuartile, secondQuartile;

    public:
    FiveNumberSummary(){}; // constructor
    ~FiveNumberSummary(){}; // destructor
    FiveNumberSummary(const FiveNumberSummary &f); // copy constructor
        
    void setMin(double val);
    double getMin();
    void setMax(double val);
    double getMax();
    void setMedian(double val);
    void setFirstQuartile(double val);
    void setSecondQuartile(double val);

    inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }
    
    // overloading "<<" operator using friend function
    friend void operator<<(FiveNumberSummary &s, ostream& newcout){
        newcout.precision(4);
        newcout << fixed;
        newcout << s.truncfunc(s.min) << "," << s.truncfunc(s.firstQuartile) << "," 
        << s.truncfunc(s.median) << "," << s.truncfunc(s.secondQuartile) << "," 
        << s.truncfunc(s.max) << " ";
    }
};