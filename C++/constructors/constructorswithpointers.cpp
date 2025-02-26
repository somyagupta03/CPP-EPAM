#include <iostream>
using namespace std;

class MyClass {
private:
    int* data;  // Pointer to dynamically allocated memory

public:
    // Constructor: Allocate memory and initialize it
    MyClass(int value) {
        // Allocate memory for an integer
        data = new int;
        // Initialize the memory with the given value
        *data = value;
        cout << "Constructor: Allocating memory and setting value to " << *data << endl;
    }

    // Destructor: Deallocate the dynamically allocated memory
    ~MyClass() {
        // Free the dynamically allocated memory
        delete data;
        cout << "Destructor: Deallocating memory" << endl;
    }

    // Function to display the value of data
    void display() const {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    cout << "Creating object with value 10." << endl;
    MyClass obj(10);  // Constructor will allocate memory and set value
    obj.display();    // Display the value

    // Destructor will automatically be called when 'obj' goes out of scope
    return 0;
}
