#include <iostream>
#include <map>
using namespace std;

int main(){
    //values stored in key-pair form, one key cant point to two values.
    //data stored sorted in ascending order
    map<int,string> m; //not as effecient as unordered map, uses o(log n) instead of o(1)
    m[1]="adi";
    m[13]="hadi";
    m[2]="aron";
    for(auto &i:m){ //printed in sorted(ascending) order of keys since its ordered map
        cout<<i.first<<endl;
        cout<<i.second<<endl;
    }
    m.insert({5,"poland"});
    m.count(13); //finds if 13 there or not
    m.erase(13); //erases 13
    auto it=m.find(5);
    for(auto i=it;i!=m.end();i++){
        cout<<(*i).first<<endl;
        cout<<(*i).second<<endl;
    }
}