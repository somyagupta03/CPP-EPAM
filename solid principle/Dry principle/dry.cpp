#include<iostream>
using namespace std;

//DRY - Dont repeat yourself , use functions and methods to follow this principle

class Button{
    public:
        virtual void onclick()=0;
};
class Submit:public Button{
    public: 
        void onclick()override{
            cout<<"submit button clicked"<<endl;
        }
};
class Cancel:public Button{
    public: 
        void onclick()override{
            cout<<"cancel button clicked"<<endl;
        }
};

int main(){
   Submit s;
   s.onclick();
   Cancel c;
   c.onclick();
   return 0;
}