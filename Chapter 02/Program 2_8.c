#include <stdio.h>
#include <stdlib.h>
int main() {
    // Declare a single pointer to an integer
    int *ptr;
    // Allocate memory for a single integer dynamically
    ptr = (int *)malloc(sizeof(int));
    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1; // Exit with an error code
    }
    // Input a value into the allocated memory
    printf("Enter an integer: ");
    scanf("%d", ptr);
    // Display the value using the pointer
    printf("Value entered: %d\n", *ptr);
    // Deallocate the allocated memory
    free(ptr);
    return 0; // Exit program successfully
}
