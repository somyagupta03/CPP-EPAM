#include<iostream>
#include<fstream>
using namespace std;

/*
The useful classes for working with files in c++ are:
1. fstreambase
2. ifstream --> derived from fstreambase
3. ofstream --> derived from fstreambase
*/

// in order to work with files in c++, you have to open it . There are 2 ways to open a file:
//1. using the constructor
//2. using the member function open() of the class 

int main(){
//opening files using constructor and writing on it
string st = "Hello Somya";
string st2;
ofstream out("sample.txt");
out<<st;

//opening files using constructor and reading from it
ifstream in("sample2.txt");
// in>>st2;
// cout<<st2;
getline(in,st2);
cout<<st2;
return 0; 
}