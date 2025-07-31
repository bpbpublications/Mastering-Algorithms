#include <stdio.h>
// Function to compute the modular inverse of a modulo m
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;
        // Update x0 and x1
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;
    return x1;
}
// Function to solve the system of congruences using CRT
int chineseRemainderTheorem(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}
// Main function to test the CRT function
int main() {
    int num[] = {3, 4, 5}; // Moduli
    int rem[] = {2, 3, 2}; // Remainders
    int k = sizeof(num) / sizeof(num[0]);
    int result = chineseRemainderTheorem(num, rem, k);
    printf("x = %d\n", result);
    return 0;
}
