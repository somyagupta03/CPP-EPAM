#include<iostream>
using namespace std;

class Person{
private:
string name;
int age;

public:
   //creating a constructor
    Person(string a,int b){
    name=a;
    age=b;
    }

    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
};
int main(){
    Person p1("somya",21); 
    p1.display();


}