#include<iostream>
#include<thread>
#include<mutex>
#include<deque>
#include<condition_variable>
using namespace std;

std::mutex m;
std::condition_variable cond;
deque<int>buffer;
const unsigned int maxbuffersize = 50;

void produce(int val){
    while(val){
        std::unique_lock<std::mutex> locker(m);
        //if buffer size is not less than 50 then the condition will wait for the buffer to get empty.
        cond.wait(locker, [](){return buffer.size()<maxbuffersize;});
        buffer.push_back(val);
        cout<<"Produced: " <<val<<Endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consume(){
    while(true){
        std::unique_lock<std::mutex> locker(m);
        cond.wait(locker,[](){return buffer.size()>0;});
        int val = buffer.back();
        buffer.pop_back();
        cout<<"Consumed: " <<val<<endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main(){ 
    std::thread t1(produce,100);
    std::thread t2(consume);

    t1.join();
    t2.join();
    return 0;
}