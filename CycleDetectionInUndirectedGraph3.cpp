#include<bits/stdc++.h>
void buildAdj(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges, int m){
    for(int i=0;i<m;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

bool dfsTraversal(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int i, int j){ //i is top and j is parent
    visited[i]=true;

    for(int k=0;k<adj[i].size();k++){
        int neighbour=adj[i][k];
        if(visited[neighbour]&&neighbour!=j) return true; //when neighbour is visited && neighbour is not parent of top then cycle is present
        if(!visited[neighbour]){
            if(dfsTraversal(adj,visited,neighbour,i)) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)  //this method is using DFS and keeps track of parent
{
    unordered_map<int,vector<int>> adj;
    buildAdj(adj,edges,m);
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if (!visited[i]) {
            if(dfsTraversal(adj,visited,i,-1)) return "Yes";
        }
    }
    return "No";
}
