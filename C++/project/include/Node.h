#ifndef NODE_H_
#define NODE_H_

#include<bits/stdc++.h>
using namespace std;

/*
    IMT2019062 Pranjal Walia
    !WARNING!
        - Do not modify this file
        - Dependency for UCINET_DL_Filter (Task5)
*/

class Node{
    private:
        int data;
        string value;
        long double degree;
        bool removed;
        
    public:
        Node();
        Node(const Node &node);
        ~Node();

        friend ostream& operator<<(ostream& out, const Node &N);

        int getNodeData();
        string getNodeValue();
        long double getNodeDegree();
        bool getNodeState();

        void setNodeData(int data);
        void setNodeValue(string value);
        void setNodeDegree(long double deg);
        void setNodeState(bool remove);
};

#endif  // NODE_H_