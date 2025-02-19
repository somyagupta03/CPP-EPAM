#include<stdio.h>
#include<stdlib.h>

int main(){
    //NULL pointer 
    int *p = NULL;
    int a = 67;
    int *ptr=&a; // pointer points to a variable . 
    printf("value of a is %x\n",ptr); // using %x to print the value in hexadeciaml format
}