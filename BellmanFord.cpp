vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) { //o(n*m)
    vector<int> distance(n+1,1e8);
    distance[src]=0;
    for(int i=1;i<n;i++){ //n-1 times
        for(int j=0;j<m;j++){ //m times
            int a=edges[j][0];
            int b=edges[j][1];
            int w=edges[j][2];
            if(distance[a]+w<distance[b]) distance[b]=distance[a]+w;
        }
    }

    //detect negative cycle (this part not needed when question says no negative cycles exist, may lead to bakchodi in test cases)
    for(int j=0;j<m;j++){
            int a=edges[j][0];
            int b=edges[j][1];
            int w=edges[j][2];
            if(distance[a]+w<distance[b]) return{-1}; //negative cycle detected
    }

    return distance;
}