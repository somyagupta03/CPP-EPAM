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
     Weight operator++(){
        kg++;
        return *this;
     }
     //postfix overloading
     Weight operator ++(int){
        Weight temp = *this;
        kg++;
        return temp;
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