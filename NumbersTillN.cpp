#include <iostream>
using namespace std;

void numberstillnincreasing(int n){
    if(n==0) return;
    cout<<n<<endl;
    numberstillnincreasing(n-1);
}

void numberstillndecreasing(int n){
    if(n==0) return;
    numberstillndecreasing(n-1);
    cout<<n<<endl;
}

int main(){
    numberstillnincreasing(9);
    numberstillndecreasing(9);
}