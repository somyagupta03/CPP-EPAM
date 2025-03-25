#include<iostream>
#include<memory>
using namespace std;

template<typename T>
class Sharedptr {
private:
	T *mem ;
	int* counter; // pointer refering to each resource 

	void incrementcounter() 
	{
		if (counter) {
			(*counter)++;
		}
	}
	void decrementcounter() {
		if (counter) {
			(*counter)--;
			if ((*counter) == 0) {
				if (mem) {
					delete mem;
					delete counter;
					mem = nullptr;
					counter = nullptr;
				}
			}
		}
	}
public:
	// default and parametrised constructor
	Sharedptr(T* ptr = nullptr) : mem(ptr),counter(new int(1)){
		cout << "constructor was called" << endl;
	} 
	// copy constructor
	Sharedptr<T>(const Sharedptr<T>& ptr) {
		cout << "copy constructor was called" << endl;
		mem = ptr.mem;
		counter = ptr.counter;
		incrementcounter();
	}
	//move copy constructor
	Sharedptr(Sharedptr&& ptr) noexcept{
		cout << "move constructor was called" << endl;

		mem = ptr.mem;
		counter = ptr.counter;
		//only the membership is passed the counter will not be incremented
		ptr.mem = nullptr;
		ptr.counter = nullptr;
	}
	//copy assignment operator
	Sharedptr& operator=(const Sharedptr& ptr) {
		// checking the self assignment
		if (this != &ptr) {
			decrementcounter();
			mem = ptr.mem;
			counter = ptr.counter;
			incrementcounter();
		}
		return *this;
	}
    // move assignment operator 
	Sharedptr<T>& operator=(Sharedptr<T>&& ptr) {
		if (this != &ptr) {
			decrementcounter();
			mem = ptr.mem;
			counter = ptr.counter;
			ptr.mem = nullptr;
			ptr.counter = nullptr;
		}
		return *this;
	}

	void reset(T* ptr = nullptr) {
		//now we have to reset the value of existing ptr and give a new value . 
		decrementcounter();
		mem = ptr;
		counter = ptr? new int(1) : nullptr;
	}
	int get_count() {
		if (counter) {
			return (*counter);
		}	
		else {
			return 0;
		}
	}

	T* operator->() const noexcept {
		return mem;
	}

	T& operator*() const noexcept {
		return *mem;
	}
	
	T* get() {
		return mem;
	}

	~Sharedptr() {
		decrementcounter();
	}
};
int main() {
	Sharedptr<int> ptr1; // default constructor
	Sharedptr<int>ptr2(new int(20)); // parametrised constructor
	Sharedptr<int>ptr3(ptr2); // copy constructor
	ptr3 = ptr2; // copy assignment operator , 
	// in this case ptr3 = ptr2 , ptr3 will leave its own resource and will start pointing to the resource of ptr2 , for this we have to decrease the pointer of ptr3 and increase the pointer of ptr2.
	
	
	Sharedptr<int>ptr4(std::move(ptr1)); // move copy constructor
	ptr2 = std::move(ptr3);// move assignment operator

	//ptr1.reset();
	ptr1.reset(new int(5));

	cout << (*ptr1) << endl; // implementing * operator 
	ptr1->func(); // implementing -> operator 

	ptr1.get(); // raw pointer
	ptr1.get_count(); // no. of objects pointing to the same resource

	return 0;
}