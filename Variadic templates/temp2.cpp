#include<iostream>
using namespace std;

template<typename T>
T sum(T arg) { return arg; }

template<typename T , typename ... Args>
auto sum(T first, Args... args) {
	return first + sum(args...);
}

int main() {
	cout << sum(1, 2.2f, 3.2, 4, 5) << std::endl;   // outputs 15.4 as i have used auto keyword.
	//cout << sum(1.5, 2.5, 3.5) << std::endl;  // Output: 7.5
	return 0;
}