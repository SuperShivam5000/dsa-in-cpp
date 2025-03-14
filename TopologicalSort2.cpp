#include <bits/stdc++.h> 

void createAdj(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges, int e){
    for(int i=0;i<e;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  { //this method use Kahn's Algo/BFS and is harder
    unordered_map<int,vector<int>> adj;
    createAdj(adj,edges,e);
    vector<int> indegree(v,0);
    for(int i=0;i<e;i++){
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto &i: adj[top]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    return ans;
}