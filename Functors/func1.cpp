#include <iostream>
 
struct Multiplier {
    int factor;
    Multiplier(int f) : factor(f) {}
 
    int operator()(int value) const {
        return value * factor;
    }
};
 
int main() {
    Multiplier times3(3);
    std::cout << times3(5) << "\n";  // Output: 15
}