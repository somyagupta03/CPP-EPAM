#include<iostream>
using namespace std;

class Rectangle{
    private:
    double length;
    double width;

    public:
    //constructor
    Rectangle(double l , double w){
        length=l;
        width=w;
        cout<<"Rectangle constructor called"<<endl;
    }

    double getlength(){
        return length;
    }
    double getwidth(){
        return width;
    }

    void setlength(double l){
        length=l;
    }
    void setwidth(double w){
        width=w;
    }

    double area(){
        return length*width;
    }

    void display(){
        cout<<"Rectangles length : "<<length <<endl;
        cout<<"Rectangles width : "<<width<<endl;
        cout<<"Rectangles area : "<<area()<<endl;

    }
};

int main(){
 
    Rectangle rect1(10.5, 5.3);
    rect1.display(); // Display initial details of the rectangle

    // Use mutator functions to change the dimensions of the rectangle
    rect1.setlength(12.0);
    rect1.setwidth(6.0);

    cout << "\nAfter modifying the dimensions:" << endl;
    rect1.display(); // Display updated details

    return 0;
}