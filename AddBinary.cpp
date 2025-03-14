#include <bits/stdc++.h> //contains all c++ headers
using namespace std;

struct carryandsum{
    int sum;
    int carry;
};

carryandsum digits(int a,int b,int c){
    int total = a+b+c;
    int sum,carry;
    if (total==0){
        sum=0;carry=0;
    }
    else if(total==1){
        sum=1;carry=0;
    }
    else if(total==2){
        sum=0;carry=1;
    }
    else if(total==3){
        sum=1;carry=1;
    }
    carryandsum c1;
    c1.sum=sum;
    c1.carry=carry;
    return c1;
}

int main(){
    int x,y;
    cin>>x;
    cin>>y;

    int i,j,a,b,c=0;
    string sum;
    for(i=x,j=y;i>0||j>0;i/=10,j/=10){
        a=i%10;
        b=j%10;
        carryandsum c1 = digits(a,b,c);
        sum=to_string(c1.sum)+sum;
        c=c1.carry;
    }
    if(c==1) sum="1"+sum;
    
    cout<<sum<<endl;
}