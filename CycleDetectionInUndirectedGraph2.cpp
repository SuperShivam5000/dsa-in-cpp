#include<bits/stdc++.h>
void buildAdj(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges, int m){
    for(int i=0;i<m;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

bool bfsTraversal(unordered_map<int,vector<int>> &adj, vector<bool> &visited, unordered_map<int,int> &parent, int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    parent[i]=-1;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        vector<int> temp = adj[top];
        for(int j=0;j<temp.size();j++){
            int neighbour=temp[j];
            if(visited[neighbour] && neighbour!=parent[top]) return true; //when neighbour is visited && neighbour is not parent of top then cycle is present

            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour]=top;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)  //this method is using BFS and keeps track of parent
{
    unordered_map<int,vector<int>> adj;
    buildAdj(adj,edges,m);
    vector<bool> visited(n,false);
    unordered_map<int,int> parent;
    for(int i=0;i<n;i++){
        if (!visited[i]) {
            if(bfsTraversal(adj,visited,parent,i)) return "Yes";
        }
    }
    return "No";
}
