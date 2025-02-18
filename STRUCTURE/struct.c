#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct Student {
	int age;
	char *name;
};

int main() {
	struct Student* p;
	//Allocating memory for the structure
	p = (struct Student*)malloc(sizeof(struct Student));
	if (p == NULL) {
		printf("Memory allocation for structure failed\n");
		return 1;  // Exit the program if allocation fails
	}

	//Allocating memory for the name
	p->name = (char*)malloc(50 * sizeof(char));
	if (p->name == NULL) {
		printf("Memory allocation for name failed\n");
		free(p);  // Free the allocated structure before exiting
		return 1;
	}
	
	p->age = 21;
	strcpy_s((*p).name, 50, "Somya");
	printf("Name: %s\n", p->name);
	printf("Age: %d\n", p->age);

	free(p->name);
	free(p);
	
	return 0;
}