#include <iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

    int i,c=0;
    for(i=1 ; i<=a ; i++){
        if(a%i==0) c++;
    }
    if(c==2) cout<<"Prime"<<endl;
    else cout<<"Not Prime"<<endl;
}