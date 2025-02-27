#include<iostream>
using namespace std;

class Print{
public:
     void show(int x){
        cout<< "int : "<<x<<endl;
     }
     void show(char y){
        cout<< "char : "<<y<<endl;
     }

};
int main(){
    Print p1;
    p1.show(34);
    return 0;
}