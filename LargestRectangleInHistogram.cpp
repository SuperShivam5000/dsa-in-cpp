class Solution {
public:
vector<int> nextSmallest(vector<int> &heights,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(s.top()!=-1&&heights[s.top()]>=heights[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallest(vector<int> &heights,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(s.top()!=-1&&heights[s.top()]>=heights[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        vector<int> prevsmallest;
        vector<int> nextsmallest;
        prevsmallest=prevSmallest(heights,n);
        nextsmallest=nextSmallest(heights,n);

        int maxarea=heights[0];
        for(int i=0;i<n;i++){
            int height=heights[i];
            if(nextsmallest[i]==-1)nextsmallest[i]=n;
            int breadth=nextsmallest[i]-prevsmallest[i]-1;
            int area=height*breadth;
            if(area>maxarea) maxarea=area;
        }
        return maxarea;
    }
};