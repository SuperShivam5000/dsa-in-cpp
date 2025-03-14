void createAdj(map<int,vector<pair<int,int>>> &adj, vector<vector<int>> &edges, int m){
    for(int i=0;i<m;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        int w=edges[i][2];
        adj[a].push_back({b,w});
    }
}

void dfsTraversal(int i,map<int,vector<pair<int,int>>> &adj, vector<bool> &visited, stack<int> &s){
    visited[i]=true;
    for(auto &j:adj[i]){
        if(!visited[j.first])dfsTraversal(j.first,adj,visited,s);
    }
    s.push(i);
}

void topologicalSort(map<int,vector<pair<int,int>>> &adj, vector<int> &toposort, int n){
    vector<bool> visited(n);
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]) dfsTraversal(i,adj,visited,s);
    }
    while(!s.empty()){
        toposort.push_back(s.top());
        s.pop();
    }
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    map<int,vector<pair<int,int>>> adj;
    createAdj(adj, edges, m);
    vector<int> toposort;
    topologicalSort(adj,toposort,n);
    vector<int> distances(n,INT_MAX);
    distances[0]=0; //set distance of source node to 0
    for(int i=0;i<toposort.size();i++){
        int x=toposort[i];
        if(distances[x]==INT_MAX) continue; //skip nodes that are having infinite distance
        for(auto &j: adj[x]){
            distances[j.first]=min(distances[j.first],distances[x]+j.second);
        }
    }
    for(int i=0;i<n;i++){
        if(distances[i]==INT_MAX) distances[i]=-1;
    }
    return distances;
}
