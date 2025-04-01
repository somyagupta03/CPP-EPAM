#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	try {
		if (b == 0) {
			throw 0;
		}
		int c = a / b;
		cout << c << endl;
	}
	catch (...) {
		cout << "exception occured" << endl;
	}
	return 0;
}