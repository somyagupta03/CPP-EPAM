// Structure pointers 
#include<stdio.h>

struct Student {
	int age;
	char name[50];
};
struct Student s1 = { 21, "somya" };
int main() {
	struct Student* ptr = &s1;
	printf("Name: %s, Age: %d\n", ptr->name, ptr->age);
	return 0;
}