#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,j,c1,c2;
    for(i=1;i<=a;i++)
    {
        c1=i+1;
        c2=1;
        for(j=a-i;j>=1;j--)
        {
            cout<<" ";
        }
        for(j=1;j<=i;j++)
        {
            c1--;
            cout<<c1;
        }
        for(j=1;j<=i-1;j++)
        {
            c2++;
            cout<<c2;
        }
        cout<<endl;
    }
}