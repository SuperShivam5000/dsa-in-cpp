#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

bool isPossible(vector <int> stalls,int k,int mid){
    int cowCount=1;
    int lastPos=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==k) return true;
            lastPos=stalls[i];
        }
    }
    return false;
}

int maxminusmin(vector<int> stalls){
    int i,n=stalls.size();
    int max=stalls[0],min=stalls[0];
    for(i=0;i<n;i++){
        if(stalls[i]>max) max=stalls[i];
        if(stalls[i]<min) min=stalls[i];
    }
    return max-min;
}

int aggressiveCows(vector<int> stalls,int k){
    sort(stalls.begin(),stalls.end());
    int s=0;
    int e=maxminusmin(stalls);
    int mid;
    int ans=-1;
    while(s<=e){
        mid=(s+e)/2;
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        } else {
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls = {4,2,1,3,6};
    int k=2;
    cout<<aggressiveCows(stalls,k)<<endl;
}