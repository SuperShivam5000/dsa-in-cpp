class Solution {
    public:
        int minSideJumps(vector<int> &obstacles) { //tabulation approach (bottom-up)
            int n=obstacles.size()-1;
            vector<vector<int>> memo(n+1,vector<int>(4,1e9));
            memo[n][0]=0;
            memo[n][1]=0;
            memo[n][2]=0;
            memo[n][3]=0;
    
            for(int x=n-1;x>=0;x--){
                for(int y=0;y<4;y++){
                    if(obstacles[x+1]!=y){
                        memo[x][y] = memo[x+1][y];
                        continue;
                    }
                    
                    int mini=1e9;
                    for(int i=1;i<=3;i++){
                        if(y!=i&&obstacles[x]!=i){
                            int temp = 1+memo[x+1][i]; //remember x+1 here
                            mini=min(mini,temp);
                        }
                    }
                    memo[x][y] = mini;
                }
            }
            return min(memo[0][2],min(1+memo[0][1],1+memo[0][3]));
        }
    };