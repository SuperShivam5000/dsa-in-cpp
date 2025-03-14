#include <iostream>
using namespace std;

bool sorted(int arr[], int n){
    if(n==1) return true;
    if(arr[0]<arr[1] && sorted(arr+1,n-1)) return true;
    else return false;
}

int main(){
    int arr[]={1,3,2,3,4,5};
    cout<<sorted(arr,5)<<endl;
}