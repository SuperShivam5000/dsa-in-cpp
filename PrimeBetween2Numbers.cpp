#include <iostream>
using namespace std;

bool prime(int n){
    int i,c=0;
    for(i=1;i<=n;i++){
        if(n%i==0) c++;
    }
    return (c==2);
}

int main(){
    int a,b;
    cin>>a;
    cin>>b;

    int i;
    for(i=a;i<=b;i++){
        if (prime(i)) cout<<i<<endl;
    }
}