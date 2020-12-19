#include<bits/stdc++.h>
#include "../include/Edge.h"
using namespace std;

/*
    IMT2019062 Pranjal Walia
    !WARNING!
        - Do not modify this file
        - Dependency for UCINET_DL_Filter (Task5)
*/


Edge::Edge(){}

Edge::Edge(int x , int y , long double w){
    src = x;
    dest = y;
    weight = w;
}

Edge::Edge(const Edge &e){
    src = e.src;
    dest = e.dest;
    weight = e.weight;
}

Edge::~Edge(){}


int Edge::getEdgeSource(){
    return src;
}

int Edge::getEdgeDestination(){
    return dest;
}

long double Edge::getEdgeWeight(){
    return weight;
}


void Edge::setEdgeSource(int src){
    this->src = src;
}

void Edge::getEdgeDestination(int dest){
    this->dest = dest;
}

void Edge::setEdgeWeight(long double weight){
    this->weight = weight;
}
