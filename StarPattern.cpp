#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,j;
    for(i=1;i<=a;i++)
    {
        for(j=a-i;j>=1;j--)
        {
            cout<<"   ";
        }
        for(j=1;j<=2*i-1;j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
    for(i=a;i>=1;i--)
    {
        for(j=a-i;j>=1;j--)
        {
            cout<<"   ";
        }
        for(j=1;j<=2*i-1;j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
} //2n-1