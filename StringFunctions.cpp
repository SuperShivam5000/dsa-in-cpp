#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    string s1="fam";
    string s2="ily";
    
    s1.append(s2); //s1=family
    cout<<s1[1]<<endl; // second character
    s1.clear(); // makes string empty
    s1="fam";
    int res = s2.compare(s1); //positive if s2>s1, zero if equal, else negative
    cout<<res<<endl;
    if(s1.compare(s2)){ //use of compare
        //do something
    }
    if(s1.empty()){ //use of empty
        //do somehting
    }
    s1="nincompoop";
    s1.erase(3, 3); //(starting index, number of characters erased)
    cout<<s1<<endl;
    s1="nincompoop";
    res = s1.find("com"); //returns starting index
    cout<<res<<endl;
    s1="nincompoop";
    s1.insert(2,"lol"); //insert at second index
    cout<<s1<<endl;
    int size = s1.length(); //length of string
    cout<<size<<endl;
    s1="nincompoop";
    s2=s1.substr(6,4); //(starting index, number of characters)
    cout<<s2<<endl;
    s1="1234";
    int x = stoi(s1); //string to integer
    cout<<x+2<<endl;
    s2=to_string(x)+"12";
    cout<<s2<<endl;
    s1="xckjgbkdfbg";
    sort(s1.begin(), s1.end()); //sort in ascending order
    cout<<s1<<endl;
    string s = "fakfjsd";
    transform(s.begin(),s.end(),s.begin(), ::toupper); //transform to upper case
    cout<<s<<endl;
    transform(s.begin(),s.end(),s.begin(), ::tolower); //transform to lower case
    cout<<s<<endl;
    sort(s.begin(),s.end(),greater<int>()); //sort in descending order
    return 0;
}