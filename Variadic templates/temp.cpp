#include<iostream>
using namespace std;

int sum() { return 0; }

template<typename T , typename ... Args>
T sum(T first, Args... args) {
	return first + sum(args...);
}

int main() {
	cout << sum(1, 2, 3, 4, 5) << std::endl;  // Output: 15
	cout << sum(1.5, 2.5, 3.5) << std::endl;  // Output: 7.5
	return 0;
}