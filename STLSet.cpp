#include <iostream>
#include <set>
using namespace std;

int main(){
    //set only stores all unique elements, repeated elements are not stored twice 
    //elements are sorted in ascending order usually.
    set<int> s;
    s.insert(1);
    s.erase(s.begin());
    for(auto i:s) cout<<i<<endl; //print all elements
    set<int>::iterator it = s.begin(); //first element
    it++; //second element
    s.count(5); //checks if 5 is there in set
    set<int>::iterator itr = s.find(5); //returns iterator of 5
    for(auto it=itr;it!=s.end();it++){
        cout<<*it<<endl;
    }
}