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

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) { //this is set method
    map<int,vector<pair<int,int>>> adj;
    createAdj(adj,vec,edges);
    set<pair<int,int>> s;
    vector<int> distances(vertices,INT_MAX);
    s.insert({source,0});
    distances[source]=0;
    while(!s.empty()){
        auto top=*s.begin();
        s.erase(s.begin());
        for(auto &i: adj[top.first]){
            if(distances[top.first]+i.second<distances[i.first]){
                auto temp=s.find({i.first,distances[i.first]});
                if(temp!=s.end()) s.erase(temp); //remember to find old pair and remove it from set. This step only for set method not required for priority queue
                distances[i.first]=distances[top.first]+i.second;
                s.insert({i.first,distances[i.first]});
            }
        }
    }
    return distances;
}
