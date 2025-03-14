#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.pop_back();
    d.pop_front();
    d.front();//first element
    d.back();//last element
    d.empty();
    d.erase(d.begin(),d.begin()+1);
}