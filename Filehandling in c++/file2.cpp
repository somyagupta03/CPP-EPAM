#include<iostream>
#include<fstream>
using namespace std;

int main(){
//connecting our file with hout stream
ofstream hout("sample.txt");

// creating a name string and filling it with the string entered by the user
string name;
cin>>name;

//writing a string to the file
hout<<name + " is my name " ;
hout.close();

ifstream hin("sample.txt");
string content;
hin>>content;
cout<<"The content of this file is : " << content;
hin.close();
return 0;
}