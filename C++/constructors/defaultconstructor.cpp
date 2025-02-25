#include<iostream>
using namespace std;

class Person{
private:
string name;
int age;

public:
   //creating a default constructor
    Person(){
    name="somya";
    age=21;
    }

    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
};
int main(){
    Person p1; 
    p1.display();


}