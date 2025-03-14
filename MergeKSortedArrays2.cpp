#include <bits/stdc++.h> 

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int d, int i, int j){
        data=d;
        row=i;
        col=j;
    }
};

class comparator{
    public:
    bool operator()(Node n1, Node n2){
        return n1.data>n2.data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node,vector<Node>,comparator> p;
    vector<int> ans;
    //push first elements
    for(int i=0;i<k;i++){
        int row=i;
        int col=0;
        Node n(kArrays[row][col],row,col);
        p.push(n);
    }
    //main part
    while(p.size()>0){
        Node top=p.top();
        ans.push_back(top.data);
        p.pop();
        int rowtoinsert=top.row;
        int coltoinsert=top.col+1;
        if(coltoinsert<kArrays[rowtoinsert].size()){
            Node n(kArrays[rowtoinsert][coltoinsert],rowtoinsert,coltoinsert);
            p.push(n);
        }
    }
    return ans;
}
