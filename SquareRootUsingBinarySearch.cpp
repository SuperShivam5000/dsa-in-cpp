#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int squarerootusingbinarysearch(int n){
    int start=0,end=n,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(mid*mid<=n&&(mid+1)*(mid+1)>n) return mid;
        else if(mid*mid>n) end=mid-1;
        else start=mid+1;
    }
    return -1;
}

int main(){
    int n=624;
    int result = squarerootusingbinarysearch(n);
    cout<<"Result:- "<<result<<endl;
}