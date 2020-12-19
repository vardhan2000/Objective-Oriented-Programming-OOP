#ifndef TASK2_H_
#define TASK2_H_

#include "./Base.h"
#include<vector>
#include<string>
using namespace std;


//! extend and implement the base
class Task2: public Base{
    vector<string> lines; // stores the info when the file is read 
    int numOfcol; // stores the number of columns in the image

public:
	// add any data members and functions that are required 


	//! make sure we have these 3 functions implemented 
    void read(string) override;
    void process() override;
    void write() override;
};

#endif // TASK2_H_