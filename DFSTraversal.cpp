void createAdj(int E, vector<vector<int>> &edges, unordered_map<int,vector<int>> &adj){
    for(int i=0;i<E;i++){
        int a=edges[i][0];
        int b=edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void traversal(unordered_map<int,vector<int>> &adj, vector<bool> &visited, vector<int> &temp, int i){
    visited[i]=true;
    temp.push_back(i);
    for(int j=0;j<adj[i].size();j++){
        if(!visited[adj[i][j]]){
            traversal(adj,visited,temp,adj[i][j]);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) //for undirected and disconnected graph
{
    unordered_map<int,vector<int>> adj;
    createAdj(E,edges,adj);
    vector<bool> visited(V);
    vector<vector<int>> ans;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> temp;
            traversal(adj,visited,temp,i);
            ans.push_back(temp);
        }
    }
    return ans;
}