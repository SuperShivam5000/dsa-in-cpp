class Solution {
    public:
        int maxSizeSlices(vector<int> &slices) { //space optimized solution
            int k=slices.size();
    
            vector<int> prev1(k+2,0); //memo1[index]
            vector<int> curr1(k+2,0); //memo1[index+1]
            vector<int> next1(k+2,0); //memo1[index+2]
    
            vector<int> prev2(k+2,0); //memo2[index]
            vector<int> curr2(k+2,0); //memo2[index+1]
            vector<int> next2(k+2,0); //memo2[index+2]
            
            for(int index=k-2;index>=0;index--){
                for(int n=1;n<=k/3;n++){
                    int include= slices[index] + next1[n-1];
                    int exclude= curr1[n];
                    prev1[n] = max(include, exclude);
                }
                next1=curr1;
                curr1=prev1;
            }
            int case1=prev1[k/3];
    
            for(int index=k-1;index>=1;index--){
                for(int n=1;n<=k/3;n++){
                    int include= slices[index] + next2[n-1];
                    int exclude= curr2[n];
                    prev2[n] = max(include, exclude);
                }
                next2=curr2;
                curr2=prev2;
            }
            int case2=prev2[k/3];
    
            return max(case1,case2);
        }
    };