#include<iostream>
using namespace std;

int main(){
    float *ptr = new float (65.77);
    int *ch = reinterpret_cast<int*>(ptr);
    cout<<"The value of ptr is "<< ptr <<endl;
    cout<<"The value of ch is "<< ch << endl;
    cout<<"The value of *ptr is "<< *ptr << endl;
    cout<<"The value of *ch is " << *ch <<endl;

    return 0;

    // it gives different result because of the memory represenation of both float and integer.
    // when casting takes place it reinterprets each bit of the float number and converts it into an integer 
    //resulting in a big integer number.

}