#include<bits/stdc++.h>
int maximumFrequency(vector<int> &arr, int n)
{
    int maxi=INT_MIN;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        maxi=max(maxi,m[arr[i]]);
    }
    int ans;
    for(int i=0;i<n;i++){
        if(m[arr[i]]==maxi){
            ans=arr[i];
            break;
        }
    }
    return ans;
}