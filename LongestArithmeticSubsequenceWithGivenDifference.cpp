class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            map<int,int> m;
            int ans=1;
            for(int i=0;i<arr.size();i++){
                int temp=arr[i]-difference;
                int tempans=1;
    
                if(m.count(temp)!=0){
                    tempans+=m[temp];
                }
    
                m[arr[i]]=tempans;
    
                ans=max(ans,tempans);
            }
            return ans;
        }
    };