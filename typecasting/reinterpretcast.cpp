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

}