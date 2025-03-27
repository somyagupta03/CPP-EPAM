#include<iostream>
using namespace std;

template<typename T , int size>
class Container {
private:
	T *data;
public:
	Container() {
		data = new T[size];
	}
	~Container() {
		delete[] data;
	}
};

int main() {
	Container<int, 5> c1;
	Container<double, 5>c2;
	return 0;
}