#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void run(int count){
    while(count-->0){
        cout<<"Cpp"<<endl;
    }
    std::this_thread::sleep_for(chrono::seconds(5));
}

int main(){
  std::thread t1(run,10);
  cout<<"main()"<<endl;
  t1.join();
  cout<<"main() after"<<endl;
  return 0;
}