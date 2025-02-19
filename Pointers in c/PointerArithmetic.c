#include<stdio.h>
#include<stdlib.h>

int main(){
    /*
    int a = 65;
    int *ptr = &a;
    printf("%d\n",ptr);
    printf("%d",ptr+1);
    */
   int arr[]={1,2,3,4,5,67};
   printf("%d\n",arr[0]);//normal way 
   //using pointers,finding the value at those positions

   printf("the value at address of second element of array is %d\n",*(arr+1));
   printf("The value at second position is %d\n",*(&arr[1]));
   return 0;
}