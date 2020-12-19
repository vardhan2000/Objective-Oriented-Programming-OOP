#include<bits/stdc++.h>
#include "../include/Face.h"
using namespace std ;

vector<Vertex> Face::getVertices() {
    return faceVertices;
}

int Face::getNumVertices() {
    return numVertices;
}

Face::Face(){
}

Face::~Face(){

}

void Face::setNumVertices(int k) {
    numVertices = k;
}

void Face::setVertices(vector<Vertex> vertices) {
    faceVertices = move(vertices);
}

double Face::getArea() {
    for(int i = 1;i < numVertices - 1; i++)
    {
        double trarea = triArea(faceVertices[0], faceVertices[i], faceVertices[i+1]);
        Triangle tr(faceVertices[0], faceVertices[i], faceVertices[i+1], trarea);
        tr.setfaceIndex(index);
        tr.setIndex(i-1);
        triangles.push_back(tr);
        area += trarea;
    }
    return area;
}
double Face::triArea(Vertex v1, Vertex v2, Vertex v3)
{
    double a = abs(sqrt(pow((v1.getX() - v2.getX()),2) + pow((v1.getY() - v2.getY()),2) + pow((v1.getZ() - v2.getZ()),2)));
    double b = abs(sqrt(pow((v2.getX() - v3.getX()),2) + pow((v2.getY() - v3.getY()),2) + pow((v2.getZ() - v3.getZ()),2)));
    double c = abs(sqrt(pow((v3.getX() - v1.getX()),2) + pow((v3.getY() - v1.getY()),2) + pow((v3.getZ() - v1.getZ()),2)));
    double s = (a+b+c)/2.0;
    double currarea = abs(sqrt(s*(s-a)*(s-b)*(s-c)));
    return currarea;
}

vector<Triangle> Face::getTriangles() {
    return triangles;
}

void Face::setIndex(int ind) {
    index = ind;
}

int Face::getIndex() {
    return index;
}

void Face::setTriangles(vector<Triangle> trs) {
    triangles = move(trs);
}
