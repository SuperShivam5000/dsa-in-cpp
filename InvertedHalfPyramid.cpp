#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,j;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=a;j++)
        {
            if(i+j<=a+1) cout<<" * ";
        }
        cout<<endl;
    }
}