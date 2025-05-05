#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Sleeping for 3 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Pause thread
    std::cout << "Woke up!\n";
    return 0;
}
