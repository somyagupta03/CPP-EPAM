#include<iostream>
using namespace std;

template <typename T>
class Uniqueptr {
private:
	T* ptr;
public:
	Uniqueptr() noexcept : ptr(nullptr) {};

	//copy constructor
	Uniqueptr(Uniqueptr const&) = delete;

	//copy assignment operator 
	Uniqueptr& operator=(Uniqueptr const&) = delete;

	//move constructor
	Uniqueptr(Uniqueptr&& o) noexcept :ptr(std::exchange(o.ptr, nullptr)) {};

	// move assignment operator
	Uniqueptr& operator=(Uniqueptr&& o) noexcept {
		delete ptr; // frees the old memory of ptr
		ptr = o.ptr;
		o.ptr = nullptr;
		return *this;
	}

	T& operator*() const noexcept {
		return *ptr;
	}

	T* operator->() const noexcept {
		return ptr;
	}
	// releases the ownership 
	T* release() noexcept {
		T* old = ptr;
		ptr = nullptr;
		return old;
	}
    //cleans up taken ownership
	void reset(T* p = nullptr) noexcept {
		delete ptr;
		ptr = p;
	}

	T* get() const noexcept {
		return ptr;
	}
};
int main() {

}