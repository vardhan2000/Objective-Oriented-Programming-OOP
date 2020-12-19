#include<bits/stdc++.h>

#include "../include/UCINET_DL_Filter.h"
#include "../include/Node.h"
#include "../include/Edge.h"

using namespace std;

/*
    IMT2019062 Pranjal Walia
        - implementation file for taks5
*/


vector<string> Task5::getLabels(string line , char delimeter){
    vector <string> tokens; 
    stringstream check1(line); 
    string intermediate; 
    while(getline(check1, intermediate, delimeter)) {   
        intermediate.erase(remove(intermediate.begin(), intermediate.end(), ' '), intermediate.end()); 
        tokens.push_back(intermediate); 
    } 
    return tokens;
}

Task5::Task5(){
    cout << "found the constructor" << endl;
}

void Task5::read(string fileName){

    string filePath = "../inputs/" + fileName;

    std::ifstream file(filePath);

    bool label_found = false;
    bool edges_found = false;
    bool nodes_found = false;

    std::string current;
    while(std::getline(file , current)){
        if(label_found){
            //! tokenise about ", "
            labels = getLabels(current , ',');
            label_found = false;
        }
        if(edges_found){
            vector<string> data = getLabels(current , ' ');
            int src = stoi(data[0]);
            int dest = stoi(data[1]);
            long double weight = stold(data[2]);
            Edge e(src , dest , weight);
            //! push a copy into the vector
            edges.push_back(e);
        }
        if(current == "labels:"){
            label_found=true;
            cout << "found the labels" << endl;
        }
        if(current[0] == 'n' and current[1] == '='){
            nodes_found = true;
            string count = current.substr(2);
            number_nodes = stoi(count);
            cout << "found the number of nodes" << endl;
        }
        if(current == "data:"){
            edges_found = true;
        }
    }
}

void Task5::process(){
    this->setNodes();
    this->compute_degree();
    this->sort_nodes_by_degree();
    this->filter_nodes();
    this->debug_nodes();
}


//! definition of the friend function to overload ostream and access the Node class

//! debug utility for graph nodes
ostream& operator<<(ostream& out, const Node &N){
    cout<<"Data: "<< N.data <<" Value: "<< N.value <<" Degree: " << N.degree <<" Is Removed?: "<< N.removed << endl; 
    return out;
}

//! debug utiity for graph edges
ostream& operator<<(ostream& out , const Edge &E){
    out << E.src << " " << E.dest << " " << E.weight << endl;
    return out;
}


void Task5::setNodes(){
    nodes.resize(number_nodes);
    for(int i=0 ; i<number_nodes ; ++i){

        Node n;
        // n.data = i+1; n.value = labels[i]; n.removed = false; n.degree = 0;
        n.setNodeData(i+1);
        n.setNodeValue(labels[i]);
        n.setNodeState(false);
        n.setNodeDegree(0);

        //! calls copy constructor on assignment
        nodes[i] = n;
    }
}

void Task5::debug_nodes(){
    cout << "Total Number of Nodes: " << nodes.size() << endl;
    for(Node n : nodes){
        //! overload ostream here
        cout << n;
        // cout<<"data: "<<n.getNodeData()<<" value: "<<n.getNodeValue()<<" degree: " <<n.getNodeDegree()<<" removed: "<< n.getNodeState()<<endl; 
    }
}

void Task5::debug_read(){
    //! call the friend of node() here
    debug_nodes();
    cout << "labels: " << endl;
    for(string s : labels)
        cout << s << endl;
    
    //! call the friend of edge() here
    cout << "Number of edges: " << edges.size() << endl;

    //! overload ostream here..
    for(Edge e : edges){
        cout << e;
    }
    // cout << e.getEdgeSource() << " " << e.getEdgeDestination() << " " << e.getEdgeWeight() << endl;
}


void Task5::compute_degree(){
    //! compute degree of nodes
    for(Node &j : nodes){
        long double wt=0;
        for(Edge e : edges){
            if(j.getNodeData() == e.getEdgeSource() || j.getNodeData() == e.getEdgeDestination()){
                wt+=e.getEdgeWeight();
            }
        }
        j.setNodeDegree(wt);
    }
}

/*
    Passing a comparator as the third parameter of std::sort is not valid. 
    Only static class members is valid.

    '''
        bool Task5::node_comparator(Node &n1 , Node &n2){
            return n1.degree > n2.degree;
        }
    '''
    Therefore the above implementation is not valid as it would be in normal functional programming.
    
    Solution: 
        Pass in an anonymous expression as a comparator i.e a lambda expression.
        ! try using const in lambda i.e const Node &n1 , const Node &n2

*/

void Task5::sort_nodes_by_degree(){
    std::sort(nodes.begin() , nodes.end() , [](Node &n1 , Node &n2){
        return n1.getNodeDegree() > n2.getNodeDegree();
    });
}

//! filter utility to seperate out the target nodes of the filtered graph
bool Task5::is_good_edge(Edge e , vector<Node*> filtered_nodes){

    bool start_good = false;
    bool end_good = false;

    int start = e.getEdgeSource(); 
    int end = e.getEdgeDestination();

    for(Node* node : filtered_nodes){
        if(node->getNodeData() == start)
            start_good = true;
        
        if(node->getNodeData() == end)
            end_good = true;
    }

    return start_good && end_good;
}



void Task5::writer(){
    freopen("../outputs/output.dl" , "w" , stdout);
}

void Task5::write(){
    
    cout << "Number of good Nodes: " << (int)filtered_nodes.size() << endl;
    cout << "Number of good edges: " << (int)filtered_edges.size() << endl;
    
    this->writer();

    cout<<"dl"<<endl;
    cout<<"format=edgelist1"<<endl;
    cout<<"n="<<(int)filtered_nodes.size()<<endl;
    cout<<"labels:"<<endl;

    set<string> locate_filtered_labels;
    for(Edge* e : filtered_edges){

        int start = e->getEdgeSource();
        int end = e->getEdgeDestination();

        locate_filtered_labels.insert(labels[--start]);
        locate_filtered_labels.insert(labels[--end]);
        
        //! revrese the pre-increment side-effect 
        //! => this side-effect can be avoided via the use of abstraction as done above 
        // ++(e->src);
        // ++(e->dest);
    }

    vector<string> filtered_labels;
    for(string label : locate_filtered_labels){
        filtered_labels.push_back(label);
    }

    for(int i=0 ; i<(int)filtered_labels.size() ; ++i){
        if(i+1 < (int)filtered_labels.size()){
            cout << filtered_labels[i] <<",";
        }
        else cout << filtered_labels[i] << endl;
    }

    cout << "data:" << endl;
    for(Edge* e : filtered_edges){
        cout << e->getEdgeSource() << " " << e->getEdgeDestination() << " " << e->getEdgeWeight() << endl;
    }
    cout << endl;

    cout << "Embedded Form: " << endl;
    for(Edge* e : filtered_edges){
        int start = e->getEdgeSource(); int end = e->getEdgeDestination();
        cout << labels[--start] << " " << labels[--end] << " " << e->getEdgeWeight() << endl;
    }
}

void Task5::filter_nodes(){
    
    //! set the "removed" field for the target nodes to be filtered
    for(int i=number_nodes-1; i>=number_nodes/2 ; --i){
        nodes[i].setNodeState(true);
    }

    if(number_nodes&1){
        nodes[(number_nodes-1)/2].setNodeState(false);
    }


    //! seperate the nodes that we filtered from the good set 

    //! refrence is important in the loop variable
    for(Node &n : nodes){
        if(n.getNodeState() == false){
            Node* new_node = &n;
            filtered_nodes.push_back(new_node);
            continue;
        }
    }

    //! refrence is imporant in the loop variable
    for(Edge &e : edges){
        //! for each edge, get the 2 nodes associated check filter for both of them
        if(is_good_edge(e , filtered_nodes)){
            Edge* new_edge = &e;
            // cout << "Good edge: " << new_edge->src << " " << new_edge->dest << endl;
            filtered_edges.push_back(new_edge);
        }
    }

}
