#include<iostream>
using namespace std;

int main(){
    int a = 3 ;
    double b = 7.9;
    double multiplication = a*b ; 
    // static_cast is done at compile time . 
    cout<<static_cast<double>(multiplication);

    return 0;
}