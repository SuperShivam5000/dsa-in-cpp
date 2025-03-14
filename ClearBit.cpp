#include <iostream>
using namespace std;

int main(){
    int n = 100;
    int i=2;
    int mult=1;
    mult=mult<<i;
    mult=~mult;
    n=n&mult;
    cout<<n<<endl;
}