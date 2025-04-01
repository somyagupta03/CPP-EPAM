#include<iostream>
#include<string>
using namespace std;

int division(int a , int b ){
    if(b==0){
        throw 0;
    }
    if(a<0 || b<0){
        throw string{"negative value occured"};
    }
    return a/b;
}

int main(){

    

}