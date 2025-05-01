#include <iostream>
#include <string>
#include <stdexcept>


class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ~Vehicle() {} 
};

class Car : public Vehicle {
public:
    void start() override {
        std::cout << "Car is starting..." << std::endl;
    }
    void stop() override {
        std::cout << "Car is stopping..." << std::endl;
    }
};

class Truck : public Vehicle {
public:
    void start() override {
        std::cout << "Truck is starting..." << std::endl;
    }
    void stop() override {
        std::cout << "Truck is stopping..." << std::endl;
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        std::cout << "Bike is starting..." << std::endl;
    }
    void stop() override {
        std::cout << "Bike is stopping..." << std::endl;
    }
};

// VehicleFactory class
class VehicleFactory {
public:
    static Vehicle* getVehicle(const std::string& vehicleType) {
        if (vehicleType == "Car") {
            return new Car();
        } else if (vehicleType == "Truck") {
            return new Truck();
        } else if (vehicleType == "Bike") {
            return new Bike();
        } else {
            throw std::invalid_argument("Unknown vehicle type");
        }
    }
};

int main() {
    Vehicle* vehicle1 = VehicleFactory::getVehicle("Car");
    vehicle1->start();
    vehicle1->stop();
    delete vehicle1;
    
    Vehicle* vehicle2 = VehicleFactory::getVehicle("Truck");
    vehicle2->start();
    vehicle2->stop();
    delete vehicle2;
    
    Vehicle* vehicle3 = VehicleFactory::getVehicle("Bike");
    vehicle3->start();
    vehicle3->stop();
    delete vehicle3;
    
    return 0;
}