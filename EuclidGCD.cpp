#include <iostream>
using namespace std;

int main(){
    int n1=140,n2=98;
    int n3=n1%n2;
    while(n3>0){
        n1=n2;
        n2=n3;
        n3=n1%n2;
    }
    cout<<n2<<endl;
}