#include <stack>
#include <algorithm>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        while(s.top()>=arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}