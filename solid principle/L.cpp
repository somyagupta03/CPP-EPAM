#include<iostream>
using namespace std;


// defination - Derived or child classes must be substitutable for their base or parent classes“.
// child class should substitute parent class seemlesly
// ensures reliability when to use polymorphism  

class Vehicle {
public:
    virtual void move() = 0;
    //virtual ~Vehicle() = default;  // Good practice: virtual destructor
};

class EngineVehicle : public Vehicle {
public:
    virtual void startEngine() = 0;
};

class NonEngineVehicle : public Vehicle {
public:
    virtual void start() = 0;
};

class Car : public EngineVehicle {
public: 
    void startEngine() override {
        cout << "Engine started of the car" << endl;
    }
    
    void move() override {
        cout << "Car is moving" << endl;
    }
};

class Cycle : public NonEngineVehicle {
public: 
    void start() override {
        cout << "Cycle started" << endl;
    }
    
    void move() override {
        cout << "Cycle is moving" << endl;
    }
};

int main() {
    Car c;
    c.startEngine();
    c.move();

    Cycle b;
    b.start();
    b.move();
    
    return 0;
}