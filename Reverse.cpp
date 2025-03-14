#include <iostream>
using namespace std;

int main(){
    int n,r,i;
    cin>>n;

    int rev=0;

    for(i=n;i>0;i/=10){
        r=i%10;
        rev=rev*10+r;
    }
    cout<<rev;
}