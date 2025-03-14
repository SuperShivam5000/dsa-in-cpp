#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int x=256;
    float sq=sqrt(x);
    if(round(sq)==sq) cout<<"Power of 2"<<endl;
    else cout<<"Not Power of 2"<<endl;
}