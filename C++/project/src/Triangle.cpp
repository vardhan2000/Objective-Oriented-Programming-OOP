#include<bits/stdc++.h>
#include "../include/Triangle.h"

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3, double area)
:v1(v1.getX(), v2.getY(), v3.getZ(), 0), v2(v2.getX(), v2.getY(), v2.getZ(), 0), v3(v3.getX(), v3.getY(), v3.getZ(), 0), area(area){
    this->trvertices.push_back(v1);
    this->trvertices.push_back(v2);
    this->trvertices.push_back(v3);
}

Triangle::~Triangle() {

}

Vertex Triangle::getV1() {
    return v1;
}

Vertex Triangle::getV2() {
    return v2;
}

void Triangle::setV1(Vertex v) {
    this->v1 = v;
}

Vertex Triangle::getV3() {
    return v3;
}

void Triangle::setV2(Vertex v) {
    this->v2 = v;
}

void Triangle::setV3(Vertex v) {
    this->v3 = v;
}

double Triangle::getArea() {
    return area;
}

int Triangle::getfaceIndex() {
    return faceindex;
}

void Triangle::setfaceIndex(int ind) {
    faceindex = ind;
}

int Triangle::getIndex() {
    return index;
}

void Triangle::setIndex(int ind) {
    index = ind;
}

vector<Vertex> Triangle::gettrVertices() {
    return trvertices;
}

