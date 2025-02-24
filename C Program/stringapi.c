#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "This is a sample string.";
    const char *needle = "sample";

    char *result = strstr(haystack, needle);

    if (result != NULL) {
        printf("Found '%s' at position: %ld\n", needle, result - haystack);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
