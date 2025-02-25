#include <iostream>
using namespace std;

class MyClass {
public:
    int value;
    string name;

    // Constructor to initialize the object
    MyClass(int v, string n) {
        value=v;
        name=n;
    }

    // Member function to display object details
    void display() {
        cout << "Value: " << value << ", Name: " << name << endl;
    }
};

int main() {
    // Array of 3 objects of type MyClass
    MyClass objects[3] = {
        MyClass(10, "Alice"),
        MyClass(20, "Bob"),
        MyClass(30, "Charlie")
    };

    // Accessing and displaying each object in the array
    for (int i = 0; i < 3; i++) {
        cout << "Object " << i + 1 << ": ";
        objects[i].display();
    }

    return 0;
}
