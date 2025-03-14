#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(5);
    q.pop();
    q.front();//first element
    q.back();//last element
    q.size();
    //we cant do q[0]=1 random access not allowed
    q.empty();
}