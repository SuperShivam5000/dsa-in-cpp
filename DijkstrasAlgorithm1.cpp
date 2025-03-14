#include <bits/stdc++.h> 

void createAdj(map<int,vector<pair<int,int>>> &adj, vector<vector<int>> &vec, int edges){
    for(int i=0;i<edges;i++){
        int a=vec[i][0];
        int b=vec[i][1];
        int w=vec[i][2];
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) { //this method use priority queue, but there is a set method also which is a bit harder
    map<int,vector<pair<int,int>>> adj;
    createAdj(adj,vec,edges);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distances(vertices,INT_MAX);
    pq.push({source,0});
    distances[source]=0;
    while(!pq.empty()){
        pair<int,int> top=pq.top();
        pq.pop();
        for(auto &i: adj[top.first]){
            if(distances[top.first]+i.second<distances[i.first]){
                distances[i.first]=distances[top.first]+i.second;
                pq.push({i.first,distances[i.first]});
            }
        }
    }
    return distances;
}
