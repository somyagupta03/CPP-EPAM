#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 5 , b = 10 ;
    int *ptra , *ptrb;

    printf("Num1 = %d and num2 = %d\n",a,b);
    ptra=&a; // giving address of a 
    ptrb=&b; // giving address of b
    
    printf("Num1 = %d and num2 = %d\n",a,b);
    *ptra=*ptra+1; //adding 1 to the value of a 
    *ptrb=*ptrb+3; // adding 3 to the value of b

    printf("num1 = %d, num2=%d\n", a,b); //printing changed value
    ptra=ptrb; // ptra->b , ptrb ->b
    ptrb=ptra; //ptrb->ptra i.e ptrb->b

    printf("num1=%d,num2=%d\n",a,b);
    printf("*ptra = %d,*ptrb=%d\n",*ptra,*ptrb);//printed 13,13

    a = *ptrb; // 13
    b=a-3; //10

    printf("num1=%d,num2=%d\n",a,b); // 13,10
    return 0;

    
}