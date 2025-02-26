#include<iostream>
using namespace std;

class Teacher{
    private:
    double salary;

    public:
     string name;
     string dept;
     string subject;
    

     //member functions
     void changedept(string newdept){
        dept=newdept;
     }
     //setter
     void setSalary(double s){
        salary = s;
     }
     //getter
     double getSalary(){
        return salary;
     }

};

int main(){
    Teacher t1;
    t1.name="Somya";
    t1.subject="c++";

}