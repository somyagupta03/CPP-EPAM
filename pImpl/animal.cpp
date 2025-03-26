#include "animal.h"


class Animal::impl
{
public:
	int fullness = 10;
};

Animal::Animal() :pImpl(std::make_unique<impl>()) {};

Animal::~Animal() = default;
Animal::Animal(Animal&& a) = default;
Animal& Animal::operator=(Animal&&) = default;

void Animal::eat(int calories) {
	pImpl->fullness += calories;
}

int Animal::getfullness() {
	return pImpl->fullness;
}