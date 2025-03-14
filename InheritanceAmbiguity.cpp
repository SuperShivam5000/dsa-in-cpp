#include <bits/stdc++.h>
using namespace std;

class A{
    public:
    void abc(){
        cout<<"Class A function"<<endl;
    }
};

class B{
    public:
    void abc(){
        cout<<"Class B function"<<endl;
    }
};

class C: public A, public B{};

int main(){
    C obj1;
    //obj1.abc(); ambiguous
    obj1.A::abc(); //abc() inherited from class A
    obj1.B::abc(); //abc() inherited from class B
    return 0;
}