#include<iostream>
using namespace std;

class Complex;

class Calculator{
    public:
        int add(int a , int b){
            return (a+b);
        }
        int sumRealComplex(Complex, Complex);
};

class Complex{
    int a, b;
    friend int Calculator :: sumRealComplex(Complex , Complex)
}
int main(){

}