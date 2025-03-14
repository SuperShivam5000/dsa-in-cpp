class Solution {
    public:
        int solve(vector<int> &obstacles,int x,int y,vector<vector<int>> &memo){
            if(x==obstacles.size()-1) return 0;
            if(memo[x][y]!=-1) return memo[x][y];
    
            if(obstacles[x+1]!=y){
                return memo[x][y] = solve(obstacles,x+1,y,memo);
            }
            
            int mini=INT_MAX;
            for(int i=1;i<=3;i++){
                if(y!=i&&obstacles[x]!=i){
                    int temp = 1+solve(obstacles,x,i,memo);
                    mini=min(mini,temp);
                }
            }
            return memo[x][y] = mini;
        }
        int minSideJumps(vector<int> &obstacles) { //recursion+memoization solution (top-down)
            vector<vector<int>> memo(obstacles.size(),vector<int>(4,-1));
            return solve(obstacles,0,2,memo);
        }
    };