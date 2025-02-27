#include<iostream>
using namespace std;

class Parent{
    public:
        void getInfo(){
            cout<<"Parent class"<<endl;
        }
};
class Child : public Parent{
    public:
    void getInfo(){
        cout<<"child  class"<<endl;
    }

};

int main(){
    Child p1;
    p1.getInfo();
    return 0;
}