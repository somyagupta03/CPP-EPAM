#include<iostream>
using namespace std;

//threads using non static member functions 
class Base{
public :
   void run(int x){
    while(x-->0){
        cout<<x<<endl;
    }
   }
};

int main(){
 Base b;
 std::thread t(&Base::run , &b,10);
 t.join();
 return 0;
}