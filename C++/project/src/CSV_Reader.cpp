#include <bits/stdc++.h>
#include "../include/CSV_Reader.h"

using namespace std;

//! these three functions will only be called in main, so make sure your code works in accordance with this 

Task8::Task8(int rstart,int cstart):rowstart(rstart),columnstart(cstart){}  // construnctor to indicate the header names

Task8::Task8(const Task8 &t81)  // copy constructor
{
    this->name = t81.name;
    this->columnstart = t81.columnstart;
    this->rowstart = t81.rowstart;
    this->ncol = t81.ncol;
    this->nrow = t81.nrow;
    matrix = new std::string*[nrow];
    for(int i=0;i<nrow;i++)
    {
        matrix[i] = new std::string[ncol];
    }
    for(int i=0;i<nrow;i++)
    {
        for(int j=0;j<ncol;j++)
        {
            matrix[i][j] = t81.matrix[i][j];
        }
    }
}

Task8::Task8(){}
Task8::~Task8() // Destructor
{
	for(int i=0;i<nrow;i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Task8::read(std::string fileName)  // read function overriden from base class
{ 
    name = fileName;
	int i,j,k;
	std::string myText;
	std::ifstream MyReadFile("../inputs/" + name); // opens the required file
    std::vector<std::string> inp;
	nrow = 0;
	ncol = 0;
    while (getline (MyReadFile, myText))    // checks the number of rows and adds each line to a vector
    {
        if(myText.length() == 0)
        {
            break;
        }
        inp.push_back(myText);
        nrow++;
    }
    for(i=0;i<inp[0].size();i++)    // checks the number of columns
    {
        if(inp[0][i] == ',')
        {
            ncol++;
        }
    }
    k = 0;
    matrix = new std::string*[nrow];    // creating the matrix of required size (nrow x ncol)
    std::string brk = "";
    for(i=0;i<nrow;i++)
    {
        matrix[i] = new std::string[ncol];
    }
    for(i=0;i<nrow;i++) // Breaks each row and creating a matrix which is a 2d array
    {
        k = 0;
        for(j=0;j<ncol-1;j++)
        {
            brk = "";
            while(inp[i][k] != ',')
            {
                brk += inp[i][k];
                k++;
            }
            matrix[i][j] = brk;
            k++;
        }
        brk = "";
        while(k < inp[i].length())
        {
            brk += inp[i][k];
            k++;
        }
        matrix[i][ncol-1] = brk;
    }
    MyReadFile.close(); // closing the file
}

void Task8::swap(std::string **x,int n1,int n2,int ncol)    // swaps 2 rows
{
	int i;
    std::string temp;
    for(i=0;i<ncol;i++)
    {
        temp = x[n1][i];
        x[n1][i] = x[n2][i];
        x[n2][i] = temp;
    }
}

bool Task8::isNumber(std::string s) // A function to check whether a string is a float or not
{
	for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == false && s[i] != '.')
        {
            return false;
        }
    }
    if(s[s.length()-1] == '.')
    {
        return false;
    }
    return true;
}

bool Task8::numericalcolumn(std::string **arr,int col,int nrows,int rowstart)   // A function to check whether an entire column is numerical or not
{
	int i;
    for(i=rowstart;i<nrows;i++)
    {
        if(isNumber(arr[i][col]) == false)
        {
            return false;
        }
    }
    return true;
}

void Task8::bubblesort(int rowstart,int colmnstart,std::string **arr,int nrow,int ncol) // Bubble sort alogorithm to sort the matrix
{
	int i,j;
    bool numfrstcol,numsndcol;
    numfrstcol = numericalcolumn(arr,colmnstart,nrow,rowstart); // checks whether the 1st column is numerical or not
    numsndcol = numericalcolumn(arr,colmnstart+1,nrow,rowstart);    // checks whether the 2nd column is numerical or not
    for(i=rowstart;i<nrow-1;i++)
    {
        for(j=rowstart;j<nrow+rowstart-i-1;j++)
        {
            if(numfrstcol)  // If the first column is numerical sorting is done numerically 
            {
                if(std::stof(arr[j][colmnstart]) > std::stof(arr[j+1][colmnstart])) // checking and swapping two rows(numerical comparision)
                {
                    swap(arr,j,j+1,ncol);
                }
                else if(std::stof(arr[j][colmnstart]) == std::stof(arr[j+1][colmnstart]))   // 2 level sorting
                {
                    if(numsndcol)   // the same applies for second column if the column is numerical, done numerical sort else lexographic sort
                    {
                        if(std::stof(arr[j][colmnstart + 1]) > std::stof(arr[j+1][colmnstart+1]))
                        {
                            swap(arr,j,j+1,ncol);
                        }
                    }
                    else
                    {
                        if(arr[j][colmnstart+1] > arr[j+1][colmnstart+1])
                        {
                            swap(arr,j,j+1,ncol);
                        }
                    }
                }
            }
            else    // if the column is not numerical sorting is done lexographically
            {
                if(arr[j][colmnstart] > arr[j+1][colmnstart])
                {
                    swap(arr,j,j+1,ncol);
                }
                else if(arr[j][colmnstart] == arr[j+1][colmnstart]) // 2 level sorting
                {
                    if(numsndcol)   // if the second column is numerical, numerical sorting is done
                    {
                        if(std::stof(arr[j][colmnstart+1]) > std::stof(arr[j+1][colmnstart+1]))
                        {
                            swap(arr,j,j+1,ncol);
                        }
                    }
                    else    // else lexographic sorting is done
                    {
                        if(arr[j][colmnstart+1] > arr[j+1][colmnstart+1])
                        {
                            swap(arr,j,j+1,ncol);
                        }
                    }
                }
            }
        }
    }
}


void Task8::process()   // overriden function process which makes the required changes
{
 	//! impelement all your workflow here, call any other functions as required after defining in this file
	bubblesort(rowstart,columnstart,matrix,nrow,ncol);
}



void Task8::write() // writes the output to a file
{
	int i,j;
	std::ofstream outfile;  
    outfile.open("../outputs/output.csv", std::ios::out | std::ios::trunc );   // opening the file in the outputs directory
    for(i=0;i<nrow;i++) // Each element of the matrix is copied into the file
    {
        for(j=0;j<ncol;j++)
        {
            outfile << matrix[i][j];
            if(j != ncol-1)
            {
                outfile << ",";
            }
        }
        if(i != nrow-1)
        {
            outfile << "\n";
        }    
    }
    outfile.close();    // closing the file
}

// getters and setters for the parameters

int Task8::getncol(){return ncol;}      
int Task8::getnrow(){return nrow;}
int Task8::getrowstart(){return rowstart;}
int Task8::getcolstart(){return columnstart;}
std::string Task8::getname(){return name;}
std::string** Task8::getmatrix(){return matrix;}

void Task8::setncol(int nc){ncol = nc;}
void Task8::setnrow(int nr){nrow = nr;}
void Task8::setrowstart(int nrs){rowstart = nrs;}
void Task8::setcolstart(int ncs){columnstart = ncs;}
void Task8::setname(int nname){name = nname;}