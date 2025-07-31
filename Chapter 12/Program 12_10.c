#include <stdio.h>
#include <math.h>

// Function to compute (base^exp) % mod using modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd
            result = (result * base) % mod;
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to compute gcd of a and b
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse of a with respect to mod
long long modInverse(long long a, long long mod) {
    long long m0 = mod, t, q;
    long long x0 = 0, x1 = 1;

    if (mod == 1)
        return 0;

    while (a > 1) {
        q = a / mod;
        t = mod;

        mod = a % mod;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    long long p = 61, q = 53;
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 17;
    long long d = modInverse(e, phi);

    printf("Public Key: (%lld, %lld)\n", e, n);
    printf("Private Key: (%lld, %lld)\n", d, n);

    long long message = 65;
    long long encrypted = modExp(message, e, n);
    long long decrypted = modExp(encrypted, d, n);

    printf("Original Message: %lld\n", message);
    printf("Encrypted Message: %lld\n", encrypted);
    printf("Decrypted Message: %lld\n", decrypted);

    return 0;
}
