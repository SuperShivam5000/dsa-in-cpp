#include <bits/stdc++.h>
using namespace std;

int main(){
    int r=7,c=5;

    //allocate
    int **arr = new int*[r];
    for(int i=0;i<r;i++){
        arr[i]= new int[c];
    }

    //deallocate
    for(int i=0;i<r;i++){
        delete[] arr[i];
    }
    delete[] arr;
}