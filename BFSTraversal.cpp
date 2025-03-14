vector<int> bfsTraversal(int n, vector<vector<int>> &adj){ //for directed and fully connected graph
    queue<int> q;
    vector<bool> visited(n);
    vector<int> ans;

    q.push(0);
    visited[0]=true; //remember to set visited as true when pushed into queue

    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(int i=0;i<adj[top].size();i++){
          if (!visited[adj[top][i]]) {
                q.push(adj[top][i]);
                visited[adj[top][i]]=true; //remember to set visited as true when pushed into queue
            }
        }
    }
    
    return ans;
}