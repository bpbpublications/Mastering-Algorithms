#include <stdio.h>

// Function to perform addition modulo
int modAdd(int a, int b, int m) {
    return (a % m + b % m) % m;
}

// Function to perform subtraction modulo
int modSub(int a, int b, int m) {
    return (a % m - b % m + m) % m; // Add m to ensure non-negative result
}

// Function to perform multiplication modulo
int modMul(int a, int b, int m) {
    return (a % m * b % m) % m;
}

// Function to perform division modulo using modular inverse (only valid for prime m)
int modDiv(int a, int b, int m) {
    // Compute modular inverse of b modulo m using Fermat's Little Theorem
    int inverse = 1;
    int exponent = m - 2; // For prime m, a^(m-1) ≡ 1 (mod m) => a^(m-2) ≡ a^(-1) (mod m)
    int base = b % m;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            inverse = (inverse * base) % m;
        }
        base = (base * base) % m;
        exponent /= 2;
    }
    return (a % m * inverse) % m;
}

int main() {
    int a = 17, b = 5, m = 7;

    printf("Addition: (%d + %d) %% %d = %d\n", a, b, m, modAdd(a, b, m));
    printf("Subtraction: (%d - %d) %% %d = %d\n", a, b, m, modSub(a, b, m));
    printf("Multiplication: (%d * %d) %% %d = %d\n", a, b, m, modMul(a, b, m));
    printf("Division: (%d / %d) %% %d = %d\n", a, b, m, modDiv(a, b, m));

    return 0;
}
