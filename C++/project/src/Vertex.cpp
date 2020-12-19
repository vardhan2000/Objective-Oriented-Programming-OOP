#include<bits/stdc++.h>
#include "../include/Vertex.h"

Vertex::Vertex(double x, double y, double z, int ind)
:x(x), y(y), z(z), index(ind){}

Vertex::~Vertex() {}

double Vertex::getX() {
    return this->x;
}

double Vertex::getY() {
    return this->y;
}

double Vertex::getZ() {
    return this->z;
}

void Vertex::setX(double x) {
    this->x = x;
}

void Vertex::setY(double y) {
    this->y = y;
}

void Vertex::setZ(double z) {
    this->z = z;
}

int Vertex::getIndex() {
    return index;
}

void Vertex::setIndex(int ind) {
    this->index = ind;
}


