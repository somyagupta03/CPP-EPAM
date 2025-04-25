#include<iostream>
using namespace std ;

/*
scenario- online platform is able to make payments through credt cards , and gpay or cod
*/

class Payment{
    virtual void payment(int amount) = 0; // pure virtual function
};

class Creditcards : public Payment{
public:
      void payment(int amt) override {
        cout<<"processing credit card payment of " << amt << endl;
      } 
};

class Gpay:public Payment{
public:
      void payment(int amt) override {
        cout<<"processing payment for gpay " <<amt<<endl;
      }
};

int main(){
    Creditcards c;
    Gpay g;
    c.payment(50);
    g.payment(100);
    return 0;
}