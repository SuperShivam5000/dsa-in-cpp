#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,j,c=0;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=a;j++)
        {
            if(i>=j)
            {
                c++;
                cout<<c<<" ";
            }
        }
        cout<<endl;
    }
}