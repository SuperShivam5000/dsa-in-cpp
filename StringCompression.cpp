#include <iostream>
#include<algorithm>

using namespace std;

int main(){
    string s= "aacbbcccaabbbaaaaacc";
    int count;
    for(int i=0;s[i]!='\0';i++){
        char current=s[i];
        count=1;
        while(s[i+1]==current){
            i++;
            count++;
        }
        if(count>=2) cout<<current<<count;
        else cout<<current;
    }
    cout<<endl;
}