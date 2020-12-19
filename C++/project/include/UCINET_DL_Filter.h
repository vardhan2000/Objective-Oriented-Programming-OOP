#ifndef UCINET_DL_FILTER_H_
#define UCINET_DL_FILTER_H_


#include<bits/stdc++.h>
using namespace std;

#include "Base.h"
#include "./Node.h"
#include "./Edge.h"

/*
    IMT2019062 Pranjal Walia
    - task5 implementation file 
    - dependencies are Base.h, Node.h, Edge.h
*/

class Task5 : public Base{
    public:
        int number_nodes;
        vector<Node> nodes;
        vector<Edge> edges;
        vector<string> labels;


        //! filter containers => no point in defining another set of nodes for the corrected filtering scheme, 
        //! instead, we can utilise the "removed" flag of each Node to filter out the target nodes
        vector<Node*> filtered_nodes;
        vector<Edge*> filtered_edges;




        // Task5(){
            // this->read();
            // this->process();
            // this->write();

        //     // // this->setNodes();
        //     // // this->compute_degree();
        //     // // this->sort_nodes_by_degree();
        //     // // this->filter_nodes();
        // }
        void read(string fileName) override;
        void process() override;
        void write() override;

        Task5();        
        void writer();
        vector<string> getLabels(string line , char delimeter);
        void setNodes();
        void debug_nodes();
        void debug_read();
        void compute_degree();
        bool node_comparator(Node &n1 , Node &n2);
        void sort_nodes_by_degree();
        void filter_nodes();
        bool is_good_edge(Edge e , vector<Node*> filtered_nodes);
};

#endif //UCINET_DL_FILTER_H_