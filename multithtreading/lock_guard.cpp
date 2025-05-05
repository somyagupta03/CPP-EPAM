#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;
int counter = 0;
void func(const char* threadno,int loopfor){
    std::lock_guard<mutex> lock(m1);
    for(int i=0;i<loopfor;i++){
        counter++;
        cout << threadno <<" "<< counter <<endl;
    }
}
int main(){
    std::thread t1(func,"T1",10);
    std::thread t2(func,"T2",10);

    t1.join();
    t2.join();
    return 0;
}