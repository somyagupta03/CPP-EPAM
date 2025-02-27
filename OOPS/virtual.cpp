#include <iostream>
using namespace std;

class Animal {
public:
    // This function is not virtual, so it cannot be overridden dynamically
     void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    // This function is not overriding the base class function, because it is not virtual
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* animal = new Animal();
    animal->speak();  // Outputs: Animal speaks

    Animal* dog = new Dog();
    dog->speak();  // Outputs: Animal speaks (not "Dog barks")

    delete animal;
    delete dog;

    return 0;
}
