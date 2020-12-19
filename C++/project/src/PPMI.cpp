#include <iostream>
#include <fstream>
using namespace std;
#include "../include/PPMI.h"

PPMI :: PPMI(){}

PPMI :: ~PPMI()
{
    delete data;
}

void PPMI :: read(std::string fileName)
{
    ifstream ifs;
    string filePath = "../inputs/" + fileName;

    ifs.open(filePath);

    ifs >> this->magicNumber;

    string myString;

    //to convert string values into integer
    ifs >> myString;
    this->width = atoi(myString.c_str());

    ifs >> myString;
    this->height = atoi(myString.c_str());

    ifs >> myString;
    this->mcv = atoi(myString.c_str());

    //The basic_string::c_str() is a builtin function in C++ which returns a pointer to an array that contains a
    //null-terminated sequence of characters representing the current value of the basic_string object.

    int MemoryBlock = this->width * this->height * 3; //This means the size is 3 bytes

    this->data = new char[MemoryBlock]; // new char array to store data of three channels (RGB)

    ifs.read(this->data, this->width * this->height * 3); //Read data into array
    ifs.close();
}

void PPMI :: process()
{
    char *flag, *reset;
    unsigned char oldRed, oldGreen, oldBlue, newRed, newGreen, newBlue;

    reset = data; // keep track of initial pointer position

    for(int i = 0; i < width * height; i++) //to change old RGBs into new RGBs using formula
    {
        flag = data;

        oldRed = *data;
        data++;

        oldGreen = *data;
        data++;
        
        oldBlue = *data;

        newRed  = (oldRed * 0.3) + (oldGreen * 0.59) + (oldBlue * 0.11);
        newGreen = (oldRed * 0.3) + (oldGreen * 0.59) + (oldBlue * 0.11);
        newBlue = (oldRed * 0.3) + (oldGreen * 0.59) + (oldBlue * 0.11);

        data = flag;

        *data = newRed;
        data++;
        
        *data = newGreen;
        data++;
        
        *data = newBlue;
        data++;
    }

    data = reset; // reset pointer position
}

void PPMI :: write()
{  
    ofstream ofs;

    ofs.open("../outputs/output.pgm", fstream::out); //generating output

    int MemoryBlock = this->width * this->height * 3;
    ofs << this->magicNumber << '\n' << this->width << ' ' << this->height << '\n' << this->mcv << '\n';
    ofs.write(this->data, MemoryBlock);
}
