
//calculator using function pointers instead of if else or switch case.

#include<iostream>
#define ops 4
using namespace std;

float sum(float a, float b){
    return a+b;
}
float sub(float a , float b){
    return a-b;
}
float mul(float a , float b){
    return a*b;
}
float div(float a, float b){
    return a/b;
}

int main(){
    //here *ptr2func[ops] is a array of pointers as [] has high precedence than *.
    // the array of pointers is pointing to function having two arguments of float type.
    
    float (*ptr2func[ops])(float,float)={sum,sub,mul,div};
    int choice;
    float a,b;
    cout<<("enter your choice: 0 for sum , 1 for sub , 2 for mul , 3 for div:\n");
    cin>>choice;
    cout<<("enter the two numbers : ")<<endl;
    cin>>a>>b;
    cout<<(ptr2func[choice](a,b));
    return 0;

}
