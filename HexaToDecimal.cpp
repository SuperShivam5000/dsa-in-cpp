#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

int main(){
    string n;
    cin>>n;

    int s = n.size();
    int i,num=0,c=0;;
    for(i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            num=num+(n[i]-'0')*pow(16,c);
        }
        else if(n[i]>='A' && n[i]<='F'){
            num=num+(n[i]-'A'+10)*pow(16,c);
        }
        c++;
    }
    cout<<num<<endl;
}