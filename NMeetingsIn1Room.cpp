class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            pair<int,int> p=make_pair(start[i],end[i]);
            arr.push_back(p);
        }
        sort(arr.begin(),arr.end(),cmp);
        int endtime=arr[0].second;
        int ans=1;
        int i=1;
        while(i<n){
            if(arr[i].first>endtime){
                ans++;
                endtime=arr[i].second;
            }
            i++;
        }
        return ans;
    }
};