#include<iostream>
using namespace std;

// here latefee class has be segregated from library class to follow srp . This segregation is interface segregation
class Latefee{
    virtual double latefee(const int days)=0;
};
// the library class only has information about the items .
class Library{
public:
    string title ;
    int uniqueid;
    virtual void property() = 0;
    // virtual void latefee()=0;  
};

class Book : public Library,public Latefee{
    string author;
    public:
    Book(string title , int id , string author){
        this->title=title;
        this->uniqueid=id;
        this->author=author;
    }
    void property() override {
        cout<<"title of book is "<< this->title<<endl;
        cout<<"uniqueid of book is " <<this->uniqueid<<endl;
        cout<<"author of book is " <<this->author<<endl;
    }
    double latefee(int days) override {
        cout<< days*20<<endl;
    }
};
int main(){
  Book b1("b1",1,"abc");
  b1.property();
  b1.latefee(2);
  return 0;
}