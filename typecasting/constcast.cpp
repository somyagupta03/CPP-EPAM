#include<iostream>
using namespace std;

void func(int *ptr){
    cout<<*ptr<<endl;
}
int main(){
    const int num1 = 40;
    const int *num2 = &num1;

    //removing the constantness by typecasting 
    int *newv = const_cast<int*>(num2);
    func(newv);

    return 0;
}