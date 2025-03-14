#include <iostream>
using namespace std;

class base{
    public:
    virtual void print(){ //dynamically binding
        cout<<"Base Class Print"<<endl;
    }
    void display(){
        cout<<"Base Class Display"<<endl;
    }
};

class derived: public base{
    public:
    void print(){
        cout<<"Derived Class Print"<<endl;
    }
    void display(){
        cout<<"Derived Class Display"<<endl;
    }
};


int main(){
    base *baseptr;
    derived d;
    baseptr=&d;
    baseptr->print();
    baseptr->display();
    return 0;
}