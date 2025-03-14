#include<bits/stdc++.h>
void buildAdj(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges, int m){
    for(int i=0;i<m;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

bool bfsTraversal(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        vector<int> temp = adj[top];
        int cnt=0;
        for(int j=0;j<temp.size();j++){
            int neighbour=temp[j];
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
            }
            else cnt++; //count number of visited nodes
        }
        if(cnt>=2) return true; //number of visited nodes >=2 means cycle exist
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) //this is the simplest logic and uses BFS
{
    unordered_map<int,vector<int>> adj;
    buildAdj(adj,edges,m);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if (!visited[i]) {
            if(bfsTraversal(adj,visited,i)) return "Yes";
        }
    }
    return "No";
}
