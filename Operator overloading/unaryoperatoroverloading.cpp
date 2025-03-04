#include<iostream>
using namespace std;

class Weight{
int kg;
public:
     Weight(){
        kg=0;
     }
     Weight(int x){
        kg = x;
     }
     void print(){
        cout<<"weight in kg is "<<kg<<endl;
     }
     //prefix overloading
     void operator ++(){
        ++kg;
     }
     //postfix overloading
     void operator ++(int){
        kg++;
     }
};

int main(){
Weight obj;
obj.print();
++obj;
obj.print();
obj++;
obj.print();
return 0;
}