#include <iostream>

class Vector2D {
public:
    float x, y;

    Vector2D(float x, float y) : x(x), y(y) {}

    // Binary subtraction operator
    Vector2D operator-(Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2D vec1(5.0, 4.0);
    Vector2D vec2(2.0, 1.0);

    Vector2D result = vec1 - vec2; // Using overloaded operator-
    result.print(); // Output should be (3, 3)

    return 0;
}