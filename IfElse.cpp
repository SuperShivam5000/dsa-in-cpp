#include <iostream>
using namespace std;

int main(){
    int savings;
    cin>>savings;
    if(savings>5000) cout<<"Rich";
    else if (savings>2000) cout<<"Middle";
    else cout<<"Poor";
}