#ifndef IMT2019058_VERTEX_H
#define IMT2019058_VERTEX_H

// Each point is represented as a vertex and every vertex has 3 coordinates
// relevant functions to set get and perform required changes have been made.
#include <bits/stdc++.h>
using namespace std;

class Vertex
{
private:
    //data members
    double x, y, z;
    int index;
public:
    Vertex(double x, double y, double z, int ind);
    ~Vertex();
    double getX();
    double getY();
    double getZ();
    int getIndex();
    void setIndex(int ind);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
};

#endif //IMT2019058_VERTEX_H
