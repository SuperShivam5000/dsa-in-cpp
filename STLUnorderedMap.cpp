#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> m; //o(1) more efficient than regular map which tales o(log n) for all operations.
    //insert
    //1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);
    //2
    pair<string,int> pair2("love",2);
    m.insert(pair2);
    //3
    m["mera"]=2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    //cout<<m.at("unknown")<<endl; //error
    cout<<m["unknown"]<<endl; //answer will be 0, creates new key
    cout<<m.at("unknown")<<endl; //now it will work since key is created

    cout<<m.size()<<endl; //prints size

    cout<<m.count("bro")<<endl; //prints 0
    cout<<m.count("love")<<endl; //prints 1

    m.erase("love"); //erases key
    cout<<m.size()<<endl;

    //printing (will not happen in any order (random) since its unordered map)
    for(auto &i:m){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    //printing using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" : "<<it->second<<endl;
        it++;
    }
}