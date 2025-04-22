#include<iostream>
using namespace std;

//threads using functors (function objects)
class Base{
public:
    void operator()(int x){
        while(x-->0){
            cout<<x<<endl;
        }
    }
};
int main(){
  std::thread t((Base()),10);
  t.join();
  return 0;
}