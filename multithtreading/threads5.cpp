#include<iostream>
using namespace std;

//threads using static member functions
class Base{
    public:
      static void run(int x){
        while(x-->0){
            cout<<x<<endl;
        }
    }
};

int main(){
    //in static member functions we dont have to send objects as arguments 
  std::thread t(&Base::run,10);
  t.join();
  return 0;
}