#ifndef PLY_FILTER_H_
#define PLY_FILTER_H_

#include<bits/stdc++.h>
#include "Face.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Base.h"

//! extend and implement the base
class Task6: public Base{

public:
	// add any data members and functions that are required
    vector<Vertex> vertices;// stores all vertices
    vector<Face> faces; // stores all faces
    vector<vector<int> > output;
    vector<Vertex> finalVertices;
    vector<int> remPos;
    int vertexNum, faceNum;
    string file_name ;

	//! make sure we have these 3 functions implemented
    void read(std::string fileName) override;
    void process() override;
    void write() override;



};

#endif //TASK1_H
