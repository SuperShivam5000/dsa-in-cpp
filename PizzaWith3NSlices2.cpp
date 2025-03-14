class Solution {
    public:
        int maxSizeSlices(vector<int> &slices) { //tabulation approach(bottom-up)
            int k=slices.size();
            vector<vector<int>> memo1(k+2,vector<int>(k+2,0));
            vector<vector<int>> memo2(k+2,vector<int>(k+2,0));
            
            for(int index=k-2;index>=0;index--){
                for(int n=1;n<=k/3;n++){
                    int include= slices[index] + memo1[index+2][n-1];
                    int exclude= memo1[index+1][n];
                    memo1[index][n] = max(include, exclude);
                }
            }
            int case1=memo1[0][k/3];
    
            for(int index=k-1;index>=1;index--){
                for(int n=1;n<=k/3;n++){
                    int include= slices[index] + memo2[index+2][n-1];
                    int exclude= memo2[index+1][n];
                    memo2[index][n] = max(include, exclude);
                }
            }
            int case2=memo2[1][k/3];
    
            return max(case1,case2);
        }
    };