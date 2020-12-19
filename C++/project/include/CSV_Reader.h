#ifndef TASK8_H_
#define TASK8_H_

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h> 
#include<ios>
#include "Base.h"

//! extend and implement the base
class Task8: public Base{

private:
	// add any data members and functions that are required 
    std::string **matrix,name;
    int nrow,ncol,rowstart,columnstart;

public:   

    Task8(int rstart,int cstart);   // constructor
    Task8();                        // Default constructor
    Task8(const Task8 &t81);        // copy constructor
    ~Task8();                       // Destructor
	//! make sure we have these 3 functions implemented 
    void read(std::string fileName);    // Read, process and write functions
    void process();
    void write();

    void swap(std::string **x,int n1,int n2,int ncol);  
    bool isNumber(std::string s);
    bool numericalcolumn(std::string **arr,int col,int nrows,int rowstart);
    void bubblesort(int rowstart,int colmnstart,std::string **arr,int nrow,int ncol);

    int getncol();      // getters and setters for the parameters
    int getnrow();
    int getrowstart();
    int getcolstart();
    std::string getname();
    std::string** getmatrix();

    void setncol(int nc);
    void setnrow(int nr);
    void setrowstart(int nrs);
    void setcolstart(int ncs);
    void setname(int nname);


};

#endif //TASK1_H
