#include<iostream>
using namespace std;


inline int sum(int a, int b){
    return a+b;
}

int main(){
    int a,b;
    cout<<"enter the value of a and b"<<endl;
    cin>>a>>b;
    cout<<"the sum of a and b is " << sum(a,b);

    return 0;

}