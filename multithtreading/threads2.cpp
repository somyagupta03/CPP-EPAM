#include<iostream>
#include<thread>
using namespace std;

//thread creation using lambda functions
int main(){
   //we can directly inject lambda at thread creation time.
//    auto fun = [](int x){
//     while (x-->0)
//     {
//         cout<<x<<endl;
//     }
//    };

   std::thread t([](int x){
    while(x-->0){
        cout<<x<<endl;
    }
   },10);
   t.join();
   return 0;
}