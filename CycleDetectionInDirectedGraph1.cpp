void createAdj(unordered_map<int,vector<int>> &adj, vector<pair<int,int>> &edges){
  for(int i=0;i<edges.size();i++){
    int a=edges[i].first;
    int b=edges[i].second;
    adj[a].push_back(b);
  }
}

void dfsTraversal(int i,vector<int> &visited, vector<int> &dfsVisited, int &ans, unordered_map<int,vector<int>> &adj){
  visited[i]=true;
  dfsVisited[i]=true;
  for(int j=0;j<adj[i].size();j++){
    if(!visited[adj[i][j]]) dfsTraversal(adj[i][j],visited,dfsVisited,ans,adj);
    if(visited[adj[i][j]] && dfsVisited[adj[i][j]]) ans=1;
  }
  dfsVisited[i]=false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) { //this method use DFS
  unordered_map<int,vector<int>> adj;
  createAdj(adj,edges);
  vector<int> visited(n+1,false); //1 based indexing thats why n+1
  vector<int> dfsVisited(n+1,false); //1 based indexing thats why n+1
  int ans=0;
  for(int i=1;i<=n;i++){ //1 based indexing thats why loop running from 1 to <=n
    if(!visited[i]) dfsTraversal(i,visited,dfsVisited,ans,adj);
  }
  return ans;
}