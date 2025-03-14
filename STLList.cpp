#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.pop_back();
    l.pop_front();
    //we cant do l[0] here random access not allowed
    l.erase(l.begin()); //delete first element
    l.erase(l.end()); //delete last element
    l.size();
    list<int>n(l); //copy list l into n
    list<int>k(5,100); //5 elements,value 100
}