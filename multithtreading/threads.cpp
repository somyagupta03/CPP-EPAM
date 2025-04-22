#include<iostream>
using namespace std;


//creation of thread using function pointer
void fun(int x){
    while(x-->0){
        cout<<x<<endl;
    }
}

int main(){
    std::thread t1(fun,10);
    t1.join();
    return 0;
}