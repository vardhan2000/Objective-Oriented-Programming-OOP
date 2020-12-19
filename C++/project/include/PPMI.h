#ifndef PPMI_H
#define PPMI_H
#include <iostream>
using namespace std;
#include "Base.h"

class PPMI : public Base
{
    private:
        string magicNumber; // A "magic number" for identifying the file type
        int width; // Width of the image
        int height; // Height of the image
        int mcv; // Maximum color value
        char *data; // A series of rows and columns that stores important binary image data or the three channels
        int MemoryBlock; // memory block

    public:
        PPMI();
        ~PPMI();

        void read(std::string fileName) override;
        void process() override;
        void write() override;
};
#endif