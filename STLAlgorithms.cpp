#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<binary_search(v.begin(),v.end(),6); //binary search
    auto itr = lower_bound(v.begin(),v.end(),6)-v.begin(); //returns iterator
    auto itr2 = upper_bound(v.begin(),v.end(),4)-v.begin(); //returns iterator
    cout<<itr<<endl;
    cout<<itr2<<endl;

    int a=3,b=4;
    max(a,b);
    min(a,b);
    swap(a,b);

    string s="abcd";
    reverse(s.begin(),s.end());

    rotate(v.begin(),v.begin()+1,v.end());

    sort(v.begin(),v.end());
}