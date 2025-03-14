#include <iostream>
using namespace std;

int main(){
    int a,i,j;
    cin>>a;

    for(i=1 ; i<=3 ; i++){
        for(j=1 ; j<=a; j++){
            if((i+j)%4==0 || (i==2 && j%4==0)) cout<<" * ";
            else cout<<"   ";
        }
        cout<<endl;
    }
}