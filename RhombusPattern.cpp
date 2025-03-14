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
        for(j=1;j<=a;j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
}