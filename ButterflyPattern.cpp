#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,j,c=0;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=i;j++) cout<<"*";
        for(j=1;j<=a*2-i*2;j++) cout<<" ";
        for(j=1;j<=i;j++) cout<<"*";
        cout<<endl;
    }
    for(i=a;i>=1;i--)
    {
        for(j=1;j<=i;j++) cout<<"*";
        for(j=1;j<=a*2-i*2;j++) cout<<" ";
        for(j=1;j<=i;j++) cout<<"*";
        cout<<endl;
    }
}