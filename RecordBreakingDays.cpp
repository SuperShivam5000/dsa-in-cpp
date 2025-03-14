#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    int n;
    cin>>n;
    int v[n];
    int i,j,c=0;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    int maxtillnow=v[0];
    for(i=0;i<n;i++){
        //test con1
        bool con1;
        if(i==0 || v[i]>maxtillnow){
            maxtillnow=v[i];
            con1=true;
        }
        else con1=false;
        //test con2
        bool con2;
        if(i==n-1 || v[i]>v[i+1]) con2 = true;
        else con2 = false;

        if(con1&&con2) c++;
    }
    cout<<"No. of record breaking days: "<<c;
    
    return 0;
}