#ifndef EDGE_H_
#define EDGE_H_

#include<bits/stdc++.h>
using namespace std;

/*
    IMT2019062 Pranjal Walia
    !WARNING!
        - Do not modify this file
        - Dependency for UCINET_DL_Filter (Task5)
*/

class Edge{

    private:
        int src;
        int dest;
        long double weight;

    public:    
        Edge();
        Edge(int x , int y , long double w);
        Edge(const Edge &e);
        ~Edge();

        friend ostream& operator<<(ostream& out , const Edge &E);

        int getEdgeSource();
        int getEdgeDestination();
        long double getEdgeWeight();

        void setEdgeSource(int src);
        void getEdgeDestination(int dest);
        void setEdgeWeight(long double weight);
};  

#endif  // EDGE_H_