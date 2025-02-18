#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare a string
    string str = "Hello, World!";
    
    // Accessing the string
    cout << "String: " << str << endl;
    
    // Length of the string
    cout << "Length: " << str.length() << endl;

    // Concatenation
    string str2 = " How are you?";
    string result = str + str2;
    cout << "Concatenated String: " << result << endl;

    // Substring
    string sub = str.substr(7, 5);  // "World"
    cout << "Substring: " << sub << endl;

    // Find a substring
    size_t pos = str.find("World");
    if (pos != std::string::npos) {
        cout << "'World' found at position: " << pos << endl;
    }
    
    return 0;
}
