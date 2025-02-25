#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;    // string type
    int age;        // int type
    float height;   // float type
    char gender;    // char type
    bool isStudent; // bool type

public:
    // Constructor with different types of variables
    Person(string n, int a, float h, char g, bool s) {
        name = n;      // Initialize string
        age = a;       // Initialize int
        height = h;    // Initialize float
        gender = g;    // Initialize char
        isStudent = s; // Initialize bool
    }

    // Display function to print the details of the person
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " meters" << endl;
        cout << "Gender: " << gender << endl;
        cout << "Is Student: " << (isStudent ? "Yes" : "No") << endl;
    }
};

int main() {
    // Creating an object with the constructor
    Person person1("Somya", 22, 1.75, 'F', true);

    // Display the details of person1
    cout << "Person 1 details:" << endl;
    person1.display();

    return 0;
}
