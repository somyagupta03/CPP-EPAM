#include <iostream>
using namespace std;

class MyClass {
private:
    int value;
    string name;

public:
    // Constructor to initialize the object
    MyClass(int v, string n) {
        value=v;
        name=n;
    }

    // Function to display the object's details
    void display() const {
        cout << "Value: " << value << ", Name: " << name << endl;
    }

    // Destructor (optional in this case)
    ~MyClass() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    // Dynamically create an object of MyClass
    MyClass* dynamicObject = new MyClass(100, "Dynamically Created");

    // Call the display function on the dynamically created object
    dynamicObject->display();

    // Delete the dynamically created object
    delete dynamicObject;

    return 0;
}
