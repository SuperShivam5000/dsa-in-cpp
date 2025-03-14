#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n) //This solution is most efficient and does not use Trie.
{
    int minLength=INT_MAX;
    for(int i=0;i<n;i++){
        minLength=min(minLength, (int)arr[i].size());
    }
    string ans;
    for(int i=0;i<minLength;i++){
        bool status=true;
        char c = arr[0][i];
        for(int j=0;j<n;j++){
            if (arr[j][i] != c) {
                status = false;
                break;
            }
        }
        if(status) ans+=c;
        else break;
    }
    return ans;
}


