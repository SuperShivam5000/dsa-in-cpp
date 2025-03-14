#include <iostream>
using namespace std;
class A{
    public:
    void func(){
        cout<<"Inherited";
    }
};

class B: public A{}; //child class //multiple classes allowed(multiple inheritance)

int main(){
    B b;
    b.func();
}