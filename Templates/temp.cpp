#include<iostream>
using namespace std;

template<typename T>
//function template
T myMax(T x , T y){
    return x+y;
}

//class template 
template<class N>
class myclass{
    public:
    N data;
    myclass(N a){
        data = a;
    }
    void display(){
        cout<<this->data<<endl;
    }

};
int main(){
  cout<<myMax<int>(3,7)<<endl;
  myclass<int>obj(6);
  obj.display();
  return 0;
}