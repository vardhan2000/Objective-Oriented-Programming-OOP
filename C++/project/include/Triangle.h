#ifndef IMT2019058_TRIANGLE_H
#define IMT2019058_TRIANGLE_H

// since each face can be split into triangles
// each face is said to be composed of multiple triangles
// a triangle is composed of three vertices and members to store relevant information and
// functions to perform relevant operations have been made

#include<bits/stdc++.h>
#include "Vertex.h"

using namespace std;

class Triangle
{
private:
    int faceindex;
    int index;
    Vertex v1, v2, v3;
    vector<Vertex> trvertices;
    double area;
public:
    Triangle(Vertex v1, Vertex v2, Vertex v3, double area);
    ~Triangle();
    int getIndex();
    void setIndex(int ind);
    int getfaceIndex();
    void setfaceIndex(int ind);
    vector<Vertex> gettrVertices();
    double getArea();
    Vertex getV1();
    Vertex getV2();
    Vertex getV3();
    void setV1(Vertex v);
    void setV2(Vertex v);
    void setV3(Vertex v);
};
#endif //IMT2019058_TRIANGLE_H
