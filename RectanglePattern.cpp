#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a;
    cin>>b;

    int i,j;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            cout<<" * ";
        }
        cout<<endl;
    }
}