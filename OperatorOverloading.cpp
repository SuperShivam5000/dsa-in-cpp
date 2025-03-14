#include <iostream>
using namespace std;

class Complex
{
    private:
    int real,imag;
    public:
    Complex(){}
    Complex(int r,int i){
        real=r;
        imag=i;
    }
    Complex operator +(Complex &obj){
        Complex res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }
    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }
};
int main(){
    Complex c1(12,3);
    Complex c2(22,3);
    Complex c3=c1+c2;
    c3.display();
}