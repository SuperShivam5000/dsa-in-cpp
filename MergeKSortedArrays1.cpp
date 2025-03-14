#include <bits/stdc++.h>

vector<int> merge(vector<int> &v1,vector<int> &v2){
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]==v2[j]){
            ans.push_back(v1[i]);
            ans.push_back(v2[j]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j]){
            ans.push_back(v1[i]);
            i++;
        }
        else {
            ans.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        ans.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    queue<vector<int>> q;
    for(int i=0;i<k;i++){
        q.push(kArrays[i]);
    }

    while(q.size()>1){
        vector<int> v1=q.front();
        q.pop();
        vector<int> v2=q.front();
        q.pop();
        q.push(merge(v1,v2));
    }
    return q.front();
}
