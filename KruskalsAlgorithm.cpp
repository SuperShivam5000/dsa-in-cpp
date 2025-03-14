#include <bits/stdc++.h>
void makeSet(vector<int> &parent,vector<int> &rank,int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}
int findSet(vector<int> &parent,int x){
  if(parent[x]==x) return x;
  else return parent[x]=findSet(parent,parent[x]);
}
void unionSet(vector<int> &parent,vector<int> &rank, int i, int j){
  i=findSet(parent, i);
  j=findSet(parent, j);
  if(rank[i]<rank[j]){
    parent[i]=j;
  }
  else if(rank[j]<rank[i]){
    parent[j]=i;
  }
  else {
    parent[j]=i;
    rank[i]++;
  }
}

bool customComp(vector<int> &a,vector<int> &b){
  return a[2]<b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent,rank,n);

  sort(edges.begin(),edges.end(),customComp);
  int ans=0;
  for(int i=0;i<edges.size();i++){
    int a=edges[i][0];
    int b=edges[i][1];
    int w=edges[i][2];
    if(findSet(parent,a)!=findSet(parent,b)){
      unionSet(parent,rank,a,b);
      ans+=w;
    }
  }
  return ans;
}