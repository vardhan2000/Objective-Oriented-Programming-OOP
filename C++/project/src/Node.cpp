#include<bits/stdc++.h>
#include "../include/Node.h"
using namespace std;

/*
    IMT2019062 Pranjal Walia
    !WARNING!
        - Do not modify this file
        - Dependency for UCINET_DL_Filter (Task5)
*/


Node::Node(){}

Node::Node(const Node &node){
    data = node.data;
    value = node.value;
    degree = node.degree;
    removed = node.removed;
}

Node::~Node(){}

void Node::setNodeData(int data){
    this->data = data;
}

void Node::setNodeValue(string value){
    this->value = value;
}

void Node::setNodeDegree(long double deg){
    this->degree = deg;
}

void Node::setNodeState(bool remove){
    this->removed = remove;
}

int Node::getNodeData(){
    return data;
}

string Node::getNodeValue(){
    return value;
}

long double Node::getNodeDegree(){
    return degree;
}

bool Node::getNodeState(){return removed;}

