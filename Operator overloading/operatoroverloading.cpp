#include<iostream>
using namespace std;

class Complex{
    int real , imag ;
    public:
          Complex(){
            real = 0 ;
            imag = 0 ;
          }
          Complex(int r , int i){
            real  = r;
            imag = i;
          }
          void print(){
            cout<<real<<"+"<<imag<<"i"<<endl;
          }

          //operator overloading syntax
          Complex operator +(Complex c){
            Complex temp;
            temp.real=real+c.real;
            temp.imag = imag + c.imag;
            return temp;

          }

};

int main(){
    Complex c1(4,5);
    Complex c2(2,5);
    Complex c3;
    c3 = c1+c2; //c3 = c1.add(c2)
    c3.print();
    return 0;

}