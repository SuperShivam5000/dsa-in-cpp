class Solution {
    public:
        static bool customcomparator(const vector<int> &a, const vector<int> &b){ //make sure to use static and const here.
            int w1=a[0];
            int l1=a[1];
            int w2=b[0];
            int l2=b[1];
    
            if(w1==w2) return l1>l2; //Sort width in ascending and height in descending order
            else return w1<w2; //Sort width in ascending order
        }
        int lis(vector<int> &arr) { //dp with binary search solution(most optimal) takes time complexity nlogn only instead of n^2
            int n=arr.size();
            vector<int> v;
            v.push_back(arr[0]);
            for(int i=1;i<n;i++){
                if(arr[i]>v.back()){ //back function returns last element of vector
                    v.push_back(arr[i]);
                }
                else {
                    int index=lower_bound(v.begin(),v.end(),arr[i]) - v.begin(); //element just bigger than arr[i]
                    v[index]=arr[i];
                }
            }
            return v.size();
        }
        int maxEnvelopes(vector<vector<int>>& envelopes) { //based on LongestIncreasingSubsequence4
            sort(envelopes.begin(),envelopes.end(),customcomparator);
            vector<int> v;
            for(int i=0;i<envelopes.size();i++){
                v.push_back(envelopes[i][1]);
            }
            return lis(v);
        }
    };