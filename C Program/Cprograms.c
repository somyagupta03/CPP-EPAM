#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! This is a C program.";
    char *token;

    // Get the first token
    token = strtok(str, " ,.!");

    // Continue getting tokens until strtok returns NULL
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ,.!"); // Call strtok again with NULL to continue
    }

    return 0;
}
