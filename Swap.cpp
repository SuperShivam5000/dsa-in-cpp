#include <iostream>
using namespace std;

void customswap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

int main(){
    int x=256;
    int y=200;
    customswap(x,y);
    cout<<x<<endl;
    cout<<y<<endl;
}