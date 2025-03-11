#include <bits/stdc++.h>
using namespace std;

class Integer {
private:
	int i;

public:
	Integer(int i = 0)
	{
		this->i = i;
	}

	// Overloading the prefix operator
	Integer& operator--()
	{
		--i;
		// returned value should be a reference to *this
		return *this;
	}

    //overloading the postfix operator
    Integer operator--(int)
    {
        // returned value should be a copy of the object before decrement
        Integer temp = *this;
        --i;
        return temp;
    }
	// Function to display the value of i
	void display()
	{
		cout << "i = " << i << endl;
	}
};

int main()
{
	Integer i1(3);

	cout << "Before decrement: ";
	i1.display();

	// Using the pre-decrement operator
	Integer i2 = --i1;

	cout << "After pre decrement: " << endl;
	cout << "i1: ";
	i1.display();
	cout << "i2: "; 
	i2.display();

    
    // Using the post-decrement operator
     i2 = i1--;
 
    cout << "After post decrement: " << endl;
    cout << "i1: ";
    i1.display();
    cout << "i2: ";  
    i2.display();
}
