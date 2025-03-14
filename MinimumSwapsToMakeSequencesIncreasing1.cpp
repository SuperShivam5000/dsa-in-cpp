class Solution {
    public:
        int solve(vector<int> &nums1, vector<int> &nums2, int i, bool swapped, vector<vector<int>> &memo){
            if(i==nums1.size()) return 0;
            if(memo[i][swapped]!=-1) return memo[i][swapped];
    
            int prev1=nums1[i-1];
            int prev2=nums2[i-1];
            if(swapped) swap(prev1,prev2);
    
            int ans=INT_MAX;
    
            //noswap
            if(prev1<nums1[i] && prev2<nums2[i]) ans=solve(nums1,nums2,i+1,false,memo);
    
            //swap
            if(prev2<nums1[i] && prev1<nums2[i]) ans=min(ans,1+solve(nums1,nums2,i+1,true,memo));
    
            return memo[i][swapped] = ans;
        }
        int minSwap(vector<int> &nums1, vector<int> &nums2) { //recursion+memoization solution(top-down)
            nums1.insert(nums1.begin(),-1);
            nums2.insert(nums2.begin(),-1);
    
            vector<vector<int>> memo(nums1.size(),vector<int>(2,-1));
            return solve(nums1,nums2,1,false,memo);
        }
    };