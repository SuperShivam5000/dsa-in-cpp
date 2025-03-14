class Solution {
    public:
        int minSideJumps(vector<int> &obstacles) { //space optimized solution
            int n=obstacles.size()-1;
            vector<int> curr(4,1e9); //memo[x]
            vector<int> next(4,1e9); //memo[x+1]
    
            next[0]=0;
            next[1]=0;
            next[2]=0;
            next[3]=0;
    
            for(int x=n-1;x>=0;x--){
                for(int y=0;y<4;y++){
                    if(obstacles[x+1]!=y){
                        curr[y] = next[y];
                        continue;
                    }
                    
                    int mini=1e9;
                    for(int i=1;i<=3;i++){
                        if(y!=i&&obstacles[x]!=i){
                            int temp = 1+next[i]; //remember next here
                            mini=min(mini,temp);
                        }
                    }
                    curr[y] = mini;
                }
                next=curr;
            }
            return min(curr[2],min(1+curr[1],1+curr[3]));
        }
    };