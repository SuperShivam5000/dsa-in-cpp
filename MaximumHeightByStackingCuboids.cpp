class Solution {
    public:
        static bool compare(const vector<int> &a,const vector<int> &b){ //here it works even without static and const idk why
            return a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2];
        }
        int lis(vector<vector<int>> &arr) { //space optimized solution
            int n=arr.size();
            vector<int> curr(n+1,0); //memo[i]
            vector<int> next(n+1,0); //memo[i+1]
            for(int i=n-1;i>=0;i--){
                for(int l=i-1;l>=-1;l--){
                    //include
                    int include=0;
                    if(l==-1 || compare(arr[i],arr[l])) include = arr[i][2]+next[i+1];
                    
                    //exclude
                    int exclude = next[l+1];
                    
                    curr[l+1] = max(include,exclude);
                }
                next=curr;
            }
            return next[0];
        }
        int maxHeight(vector<vector<int>> &cuboids) { //based on LongestIncreasingSubsequence3
            for(int i=0;i<cuboids.size();i++){ //sort each cuboid
                sort(cuboids[i].begin(),cuboids[i].end());
            }
    
            sort(cuboids.begin(),cuboids.end()); //sort according to width/length
    
            return lis(cuboids);
        }
    };