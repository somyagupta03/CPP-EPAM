#include<iostream>
using namespace std;

class Base{
  virtual void func(){};
};

class Derived : public Base{};

int main(){
  Base *ptr = new Derived;
  Derived *pd = dynamic_cast<Derived*>(ptr);
  if(pd!=NULL){
    cout<<"dynamic casting succesfully done"<<endl;
  }
  else{
    cout<<"Not done"<<endl;
  }
  return 0;
}