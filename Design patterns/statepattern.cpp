#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

// Forward declaration
class TrafficLightState;

// Context class - Traffic Light
class TrafficLight {
private:
    std::shared_ptr<TrafficLightState> currentState;

public:
    TrafficLight();

    void setState(std::shared_ptr<TrafficLightState> newState);
    void change();
    void showStatus() const;
};

// State interface
class TrafficLightState {
public:
    virtual void handle(TrafficLight* context) = 0;
    virtual void showStatus() const = 0;
    virtual ~TrafficLightState() = default;
};

// Concrete states
class RedState : public TrafficLightState {
public:
    void handle(TrafficLight* context) override;
    void showStatus() const override {
        std::cout << "RED LIGHT - STOP!" << std::endl;
    }
};

class YellowState : public TrafficLightState {
public:
    void handle(TrafficLight* context) override;
    void showStatus() const override {
        std::cout << "YELLOW LIGHT - CAUTION!" << std::endl;
    }
};

class GreenState : public TrafficLightState {
public:
    void handle(TrafficLight* context) override;
    void showStatus() const override {
        std::cout << "GREEN LIGHT - GO!" << std::endl;
    }
};

// TrafficLight implementation
TrafficLight::TrafficLight() {
    currentState = std::make_shared<RedState>();
}

void TrafficLight::setState(std::shared_ptr<TrafficLightState> newState) {
    currentState = newState;
}

void TrafficLight::change() {
    currentState->handle(this);
}

void TrafficLight::showStatus() const {
    currentState->showStatus();
}

// State transitions
void RedState::handle(TrafficLight* context) {
    std::cout << "Changing from RED to GREEN..." << std::endl;
    context->setState(std::make_shared<GreenState>());
}

void YellowState::handle(TrafficLight* context) {
    std::cout << "Changing from YELLOW to RED..." << std::endl;
    context->setState(std::make_shared<RedState>());
}

void GreenState::handle(TrafficLight* context) {
    std::cout << "Changing from GREEN to YELLOW..." << std::endl;
    context->setState(std::make_shared<YellowState>());
}

// Simulation function
void simulateTrafficLight(TrafficLight& light, int cycles) {
    for (int i = 0; i < cycles; ++i) {
        light.showStatus();
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait 2 seconds
        light.change();
    }
}

int main() {
    TrafficLight trafficLight;
    
    std::cout << "=== Traffic Light Simulation ===" << std::endl;
    std::cout << "Running through 3 full cycles..." << std::endl << std::endl;
    
    simulateTrafficLight(trafficLight, 6); // 6 changes = 3 full cycles (R->G->Y->R->G->Y->R)
    
    std::cout << std::endl << "Simulation complete!" << std::endl;
    
    return 0;
}