#include<queue>
#include<climits>
class Node{
    public:
    int data;
    int row;
    int col;
    Node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class comparator{
    public:
    bool operator()(Node a,Node b){
        return a.data>b.data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node,vector<Node>,comparator> p;
    int maxi=INT_MIN;
    int mini=INT_MAX;
    //push all elements
    for(int i=0;i<k;i++){
        maxi=max(maxi,a[i][0]);
        mini=min(mini,a[i][0]);
        Node n(a[i][0],i,0);
        p.push(n);
    }
    int ansmaxi=maxi;
    int ansmini=mini;
    while(!p.empty()){
        Node top=p.top();
        p.pop();
        mini=top.data;

        if(maxi-mini<ansmaxi-ansmini){
            ansmaxi=maxi;
            ansmini=mini;
        }
        
        if(top.col+1<a[top.row].size()){
            Node n(a[top.row][top.col+1],top.row,top.col+1);
            maxi=max(n.data,maxi);
            p.push(n);
        } else break;
    }
    return (ansmaxi-ansmini+1);
}