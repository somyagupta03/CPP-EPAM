#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int amount = 0 ;
std::mutex m ;

void counter(){
    for(int i = 0 ;i<10000;i++){
        if(m.try_lock()){
            amount++;
            m.unlock();
        }
    }
}

int main(){
    std::thread t1(counter);
    std::thread t2(counter);

    t1.join();
    t2.join();

    cout<<amount<<endl;
    return 0;

}