#include<bits/stdc++.h>
void createAdj(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges, int e){
    for(int i=0;i<e;i++){
        int a=edges[i][0];
        int b=edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void dfsTraversal(int i,unordered_map<int,vector<int>> &adj,int &timer,
    int parent,vector<int> &discoverytime,vector<int> &lowesttime,
    vector<bool> &visited, vector<vector<int>> &result){
        visited[i]=true;
        discoverytime[i]=timer;
        lowesttime[i]=timer;
        timer++;

        for(auto &j: adj[i]){
            if(j==parent) continue; //ignore parent
            if(!visited[j]){
                dfsTraversal(j,adj,timer,i,discoverytime,lowesttime,visited,result);
                lowesttime[i]=min(lowesttime[i],lowesttime[j]);
                //check if bridge
                if(lowesttime[j]>discoverytime[i]) {
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    result.push_back(ans);
                }
            }else{
                lowesttime[i]=min(lowesttime[i],discoverytime[j]); //back edge case(already visited and not parent)
            }
        }
    }

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) { //this question uses tarjan's algorithm
    unordered_map<int,vector<int>> adj;
    createAdj(adj,edges,e);

    int timer=0;
    int parent=-1;
    vector<int> discoverytime(v,-1);
    vector<int> lowesttime(v,-1);
    vector<bool> visited(v,false);
    vector<vector<int>> result;

    for(int i=0;i<v;i++){
        if(!visited[i]) dfsTraversal(i,adj,timer,parent,discoverytime,lowesttime,visited,result);
    }

    return result;
}