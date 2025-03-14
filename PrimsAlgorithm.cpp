#include <bits/stdc++.h> 
void createAdj(map<int,vector<pair<int,int>>> &adj,vector<pair<pair<int, int>, int>> &g,int m){
    for(int i=0;i<m;i++){
        int a=g[i].first.first;
        int b=g[i].first.second;
        int w=g[i].second;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    map<int,vector<pair<int,int>>> adj;
    createAdj(adj,g,m);

    vector<int> distance(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    vector<bool> included(n+1,false);
    distance[1]=0;
    parent[1]=-1;

    for(int count=0;count<n-1;count++){ //runs n-1 times
        //find minimum weight (can be optimized further with heap)
        int minweight=INT_MAX;
        int minnode;
        for(int i=1;i<=n;i++){
            if(distance[i]<minweight && !included[i]){
                minweight=distance[i];
                minnode=i;
            }
        }
        included[minnode]=true; //include minimum node

        //traverse minnode
        for(auto &j:adj[minnode]){
            if(j.second<distance[j.first]&&!included[j.first]){
                distance[j.first]=j.second;
                parent[j.first]=minnode;
            }
        }
    }
    //create answer
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){ //since 1 is source and will have parent -1 always
        if(parent[i]!=-1)ans.push_back({{parent[i],i},distance[i]});
    }
    return ans;
}
