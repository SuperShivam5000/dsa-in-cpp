#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> maxi; //max heap form, always returns max element when popped
    priority_queue<int,vector<int>,greater<int>> mini; //min heap form, always returns min element when popped
    maxi.push(1);
    int t=maxi.top();
    maxi.pop();
    maxi.empty();
    maxi.size();
    //we cant do q[0]=1 random access not allowed
}