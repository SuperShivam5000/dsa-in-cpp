vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> adj(n,(m,vector<int>(0)));
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}