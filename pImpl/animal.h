#include<memory>

class Animal {
public:
	void eat(int calories);
	int getfullness();

	Animal();
	~Animal();

	Animal(Animal&& a);
	Animal& operator=(Animal&&);

	//delete the copy constructor and assignment operator
	Animal(const Animal& a) = delete;
	Animal& operator=(const Animal&) = delete;
private:
	class impl;
	std::unique_ptr<impl>pImpl;
};
