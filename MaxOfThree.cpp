#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;

    int g;
    if (a>b && b>c) g=a;
    else if (b>a && b>c) g=b;
    else if (c>a && c>b) g=c;

    cout<<"Greatest Number: "<<g<<endl;
}