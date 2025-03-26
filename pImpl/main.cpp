#include<iostream>
#include "animal.h"
using namespace std;

int main() {
	Animal cat;

	cout << "cat fullness before eating: " << cat.getfullness() << endl;

	cat.eat(10);

	cout << "cat fullness after eating: " << cat.getfullness() << endl;
}