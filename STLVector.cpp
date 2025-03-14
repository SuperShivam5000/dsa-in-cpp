#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    v.size();//size
    v.capacity();//capacity
    v.push_back(5);//add item
    v.front(); //first element
    v.back(); //second element
    v.pop_back();//pop
    v.clear(); //size becomes 0 but capacity remains
    vector<int> a(5,1); //11111
    vector<int> b(a); //b=a
}