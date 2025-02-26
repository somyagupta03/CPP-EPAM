#include<iostream>
using namespace std;

class Student {
    public:
    string name;
    double *cgpaPtr;

    //constructor
    Student(string name,double cgpa){
        this->name = name;
        cgpaPtr = new double ;
        *cgpaPtr = cgpa;
    }

    //copy constructor
    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double ; 
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"cgpa : "<<*cgpaPtr<<endl;
    }


};
int main(){
   Student s1("somya",8.9);
   Student s2(s1);

   s1.getinfo();
   *(s2.cgpaPtr) = 9.2;
   s2.getinfo();

   return 0;
}