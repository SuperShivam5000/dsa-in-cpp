#include <iostream>
using namespace std;

int main(){
    int i,j,n=4;
    int last = 1<<n;
    char letter;
    for(i=0;i<last;i++){
        cout<<"{";
        for(j=0;j<n;j++){
            if(((i>>j)&1)==1) {
                letter='a'+j;
                cout<<(letter);
                };
        }
        cout<<"}"<<endl;
    }
}