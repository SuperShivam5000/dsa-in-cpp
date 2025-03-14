class Solution {
    public:
        int minSwap(vector<int> &nums1, vector<int> &nums2) { //tabulation approach(bottom-up)
            nums1.insert(nums1.begin(),-1);
            nums2.insert(nums2.begin(),-1);
    
            int n=nums1.size();
            vector<vector<int>> memo(n+1,vector<int>(2,0));
            for(int i=n-1;i>=1;i--){
                for(int j=1;j>=0;j--){
                    int prev1=nums1[i-1];
                    int prev2=nums2[i-1];
                    if(j) swap(prev1,prev2);
    
                    int ans=INT_MAX;
    
                    //noswap
                    if(prev1<nums1[i] && prev2<nums2[i]) ans=memo[i+1][false];
    
                    //swap
                    if(prev2<nums1[i] && prev1<nums2[i]) ans=min(ans,1+memo[i+1][true]);
    
                    memo[i][j] = ans;
                }
            }
            return memo[1][0];
        }
    };