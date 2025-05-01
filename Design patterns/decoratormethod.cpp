#include<iostream>
using namespace std;

class Pizza{
public :
   virtual int cost()=0;
};

class Farmhouse : public Pizza{
public: 
  int cost() override {
     return 200;
}
};

class Toppingsdecorator : public Pizza{
protected:
    Pizza* basepizza;
public:
    Toppingsdecorator(Pizza* pizza){
      this->basepizza=pizza;
}
};

class Extracheese : public Toppingsdecorator{
public: 
  Extracheese(Pizza* pizza):Toppingsdecorator(pizza){}
int cost()override{
  return (basepizza->cost()+10);
}    
};

int main(){
    Pizza* pizza = new Extracheese(new Farmhouse());
   cout<< pizza->cost(); 
    return 0;
}