#ifndef IMT2019058_FACE_H
#define IMT2019058_FACE_H

// The model can be split into multiple faces.
// Each face is composed of triangles
// there are functions implemented to store area, set required values and perform relevant operations

#include<bits/stdc++.h>

#include "Vertex.h"
#include "Triangle.h"
using namespace std;

class Face
{
private:
    int index;
    vector<Vertex> faceVertices;
    int numVertices;
    vector<Triangle> triangles;
    double area;
public:
    Face();
    ~Face();
    int getNumVertices();
    void setNumVertices(int k);
    void setVertices(vector<Vertex> vertices);
    vector<Vertex> getVertices();
    double getArea();
    double triArea(Vertex v1, Vertex v2, Vertex v3);
    void setTriangles(vector<Triangle> trs);
    vector<Triangle> getTriangles();
    void setIndex(int ind);
    int getIndex();
};

// vector<Vertex> Face::getVertices() {
//     return faceVertices;
// }
//
// int Face::getNumVertices() {
//     return numVertices;
// }
//
// Face::Face() = default;
//
// Face::~Face() {}
//
// void Face::setNumVertices(int k) {
//     numVertices = k;
// }
//
// void Face::setVertices(vector<Vertex> vertices) {
//     faceVertices = move(vertices);
// }
//
// double Face::getArea() {
//     for(int i = 1;i < numVertices - 1; i++)
//     {
//         double trarea = triArea(faceVertices[0], faceVertices[i], faceVertices[i+1]);
//         Triangle tr(faceVertices[0], faceVertices[i], faceVertices[i+1], trarea);
//         tr.setfaceIndex(index);
//         tr.setIndex(i-1);
//         triangles.push_back(tr);
//         area += trarea;
//     }
//     return area;
// }
// double Face::triArea(Vertex v1, Vertex v2, Vertex v3)
// {
//     double currarea = abs(0.5*(v1.getX()*(v2.getY()*v3.getZ() - v3.getY()*v2.getZ())-v1.getY()*(v2.getX()*v3.getZ() - v2.getZ()*v3.getX()) + v1.getZ()*(v2.getX()*v3.getY()-v3.getX()*v2.getY())));
//     return currarea;
// }
//
// vector<Triangle> Face::getTriangles() {
//     return triangles;
// }
//
// void Face::setIndex(int ind) {
//     index = ind;
// }
//
// int Face::getIndex() {
//     return index;
// }
//
// void Face::setTriangles(vector<Triangle> trs) {
//     triangles = move(trs);
// }

#endif //IMT2019058_FACE_H
