#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i;

    int a=0,b=1,c;
    if(n>=1) cout<<a<<endl;
    if(n>=2) cout<<b<<endl;
    for(i=3;i<=n;i++){
        c=a+b;
        cout<<c<<endl;
        a=b;
        b=c;
    }
}