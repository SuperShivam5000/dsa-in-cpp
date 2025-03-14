#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin>>n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();

    int i, c=1, max=0;
    for(i=0;true;i++){
        if(arr[i]==' ' || arr[i]=='\0'){
            if(c>max) max=c;
            c=1;
        }
        else c++;
        if(arr[i]=='\0') break;
    }
    cout<<max<<endl;
}