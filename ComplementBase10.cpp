#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int x=5;
    int mask=0;
    int c=0;
    for(int i=x;i>0;i=i/2){
        mask=mask+pow(2,c);
        c++;
    }
    int y=(~x)&mask;
    cout<<y<<endl;
}