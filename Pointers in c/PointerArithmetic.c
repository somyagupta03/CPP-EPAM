#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 65;
    int *ptr = &a;
    printf("%d\n",ptr);
    printf("%d",ptr+1);
    return 0;
}