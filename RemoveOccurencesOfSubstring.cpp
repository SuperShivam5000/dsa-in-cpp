#include <iostream>
#include<algorithm>

using namespace std;

int main(){
    string s= "sagabcdfgabcrtetabcewgfgfabcerfwefsdfhfhfhdfabcsdgf";
    string part="abc";
    while(s.length()>0&&s.find(part)!=-1){
        s.erase(s.find(part),part.length());
    }
    cout<<s<<endl;
}