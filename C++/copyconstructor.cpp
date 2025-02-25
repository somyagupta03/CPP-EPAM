#include<iostream>
using namespace std;

class Person{
private:
string name;
int age;

public:
     // Parameterized constructor
     Person(string n, int a) {
        name = n;
        age = a;
    }

    // Copy constructor
    Person(const Person &p) {
        name = p.name;  // Copy name from the existing object
        age = p.age;    // Copy age from the existing object
        cout << "Copy constructor called!" << endl;
    }
    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
};
int main(){
     // Create an object using the parameterized constructor
     Person person1("Alice", 25);
     cout << "Person 1 details:" << endl;
     person1.display();
 
     // Create a new object using the copy constructor
     Person person2 = person1;  // This invokes the copy constructor
     cout << "Person 2 details (after copy):" << endl;
     person2.display();
 
     return 0;

}