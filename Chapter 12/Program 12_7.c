#include <stdio.h>

// Function to calculate GCD using Euclid's algorithm
int euclidGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Main function to test the GCD function
int main() {
    int a = 56;
    int b = 98;

    printf("The GCD of %d and %d is %d\n", a, b, euclidGCD(a, b));

    return 0;
}
