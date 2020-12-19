#include <bits/stdc++.h>
#include "../include/Vertex.h"
#include "../include/Triangle.h"
#include "../include/Face.h"
#include "../include/PLY_Filter.h"
#include <string>



using namespace std;

//! these three functions will only be called in main, so make sure your code works in accordance with this

void Task6::read(string fileName){
	this->file_name = fileName;
	//! all input files are stored inside a folder called inputs
	string filePath = "../inputs/" + fileName;

	// now open using the filepath
    string curr, curr2;
    ifstream inputFile(filePath);

    int line = 0;
    int flag ;
    while(curr != "end_header" &&  line != 9)
    {
        getline(inputFile, curr);
        if(curr == "end_header")
        {
            break;
        }

        stringstream currstream(curr);
        flag = 1;

        string temp;
        stringstream ss(curr);
        while(getline(ss,temp,' ')){
            if(temp == "comment"){
                flag = 0 ;
            }
        }

        if(flag == 0)
            continue;

        if(line == 2)
        {
            int pos = 0;

            while(getline(currstream, curr2, ' '))
            {
                if(pos == 2)
                {
                    vertexNum = stoi(curr2);
                }

                pos += 1;
            }
        }
        else if(line == 6)
        {
            int pos = 0;
            while(getline(currstream, curr2, ' '))
            {
                if(pos == 2)
                {
                    faceNum = stoi(curr2);
                }
                pos += 1;
            }
        }
        line += 1;
    }

    for(int i = 0;i < vertexNum; i++)
    {
        getline(inputFile, curr);
        stringstream currstream(curr);
        vector<double> positions;
        while(getline(currstream, curr2, ' '))
        {
            positions.push_back(stod(curr2));
        }

        Vertex newVert(positions[0], positions[1], positions[2], i);
        vertices.push_back(newVert);
    }

    for(int i = 0;i < faceNum; i++)
    {
        vector<Vertex> currFace;
        getline(inputFile, curr);
        stringstream currstream(curr);

        Face face ;
        face.setIndex(i);

        int pos = 0;

        while(getline(currstream, curr2, ' '))
        {
            if(pos == 0)
            {
                face.setNumVertices(stoi(curr2));
            }
            else
            {
                currFace.push_back(vertices[stoi(curr2)]);
            }
            pos += 1;
        }

        face.setVertices(currFace);
        face.getArea();
        faces.push_back(face);
    }

    inputFile.close();
}

 void Task6::process(){
 	//! impelement all your workflow here, call any other functions as required after defining in this file

 	vector<Triangle> allTriangles;
     for(auto & face : faces)
     {
         vector<Triangle> tr = face.getTriangles();
         for(auto & j : tr)
         {
             allTriangles.push_back(j);
         }
     }

     sort(allTriangles.begin(), allTriangles.end(),[&](Triangle &n1 , Triangle &n2){
         return n1.getArea() < n2.getArea();
     });

     int numTriangles = allTriangles.size();
     int remove = floor(numTriangles*0.1);
     for(int i = 0;i < remove; i++)
     {
         int faceInd = allTriangles[i].getfaceIndex();
         int triangleInd = allTriangles[i].getIndex();
         vector<Triangle> trs = faces[faceInd].getTriangles();//.erase(triangleInd);
         trs.erase(trs.begin()+triangleInd);
         faces[faceInd].setTriangles(trs);
         allTriangles.erase(allTriangles.begin()+i);
     }

     for(int i = 0;i < vertices.size(); i++)
     {
         int update = 0;
         for(auto & allTriangle : allTriangles) {
             int count = 0;
             while(count < 3) {

                 if ((vertices[i].getX() == allTriangle.gettrVertices()[count].getX()) &&
                     (vertices[i].getY() == allTriangle.gettrVertices()[count].getY()) &&
                     (vertices[i].getZ() == allTriangle.gettrVertices()[count].getZ())) {
                     update += 1;
                 }
                 count += 1;
             }
         }
         if(update == 0)
         {
             remPos.push_back(i);
         }
     }

     for(int i = 0; i < vertices.size(); i++)
     {
         int up = 0;
         for(int remPo : remPos)
         {
             if(i == remPo)
             {
                 up -= 1;
                 break;
             }
         }
         if(up >= 0)
         {
             finalVertices.push_back(vertices[i]);
         }
     }


     for(auto & face : faces)
     {
         for(int l = 0; l < face.getTriangles().size(); l++)
         {
             vector<int> subout;
             subout.push_back(3);
             for(int m = 0; m < 3; m++)
             {
                 for(int k = 0; k < vertices.size(); k++)
                 {
                     if ((face.getTriangles()[l].gettrVertices()[m].getX() == vertices[k].getX()) &&
                         (face.getTriangles()[l].gettrVertices()[m].getY() == vertices[k].getY()) &&
                         (face.getTriangles()[l].gettrVertices()[m].getZ() == vertices[k].getZ()))
                     {
                         subout.push_back(k);
                     }
                 }
             }
             output.push_back(subout);
         }
     }
}


void Task6::write(){

    string outPath = "../outputs/output.ply";
    string curr, curr2;

    ofstream outputFile(outPath);
    ifstream input("../inputs/" + this->file_name);
    int line = 0;
    int flag = 0;
    while(curr != "end_header" &&  line != 9)
    {
        getline(input, curr);

        stringstream currstream(curr);
        flag = 1;

        string temp;
        stringstream ss(curr);
        while(getline(ss,temp,' ')){
            if(temp == "comment"){
                outputFile << curr << endl;
                flag = 0 ;
                break;
            }
        }
//
        if(flag == 0)
            continue;

        if(line == 2)
        {
            outputFile << "element vertex " + to_string(finalVertices.size()) << endl;
        }
        else if(line == 6)
        {
            outputFile << "element face "+to_string(output.size()) << endl ;
        }
        else
        {
            outputFile << curr << endl;
        }
        line += 1;
    }


    for(int i = 0;i < finalVertices.size(); i++)
    {
        outputFile << finalVertices[i].getX() << ' ' << finalVertices[i].getY() << ' ' << finalVertices[i].getZ() << endl;
    }

    for(int i = 0; i < output.size(); i++)
    {
        int j = 0;
        for( ; j < output[i].size() - 1; j++)
        {
            outputFile << output[i][j] << ' ';
        }
        outputFile << output[i][j] << endl;
    }

    input.close();
    outputFile.close();
}
