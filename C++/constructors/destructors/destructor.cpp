#include<iostream>
using namespace std;

class A{
private:
string name;
int age;

public:
A(string n,int a){
    name=n;
    age=a;
    cout<<"constructor called"<<endl;
}
~A(){
    cout<<"destructor called"<<endl;
}
void display(){
    cout<<"name : "<<name<<endl;
    cout<<"age : "<<age<<endl;
}
};
int main(){
    A obj("somya",21);
    obj.display();

    return 0;

}