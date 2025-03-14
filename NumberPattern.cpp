#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,j,c;
    for(i=1;i<=a;i++)
    {
        c=0;
        for(j=a-i;j>=1;j--)
        {
            cout<<" ";
        }
        for(j=1;j<=i;j++)
        {
            c++;
            cout<<c<<" ";
        }
        cout<<endl;
    }
}