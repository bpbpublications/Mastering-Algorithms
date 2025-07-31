#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function to split a number into two halves
pair<string, string> split(const string& num, int m) {
    int len = num.length();
    string left = num.substr(0, len - m);
    string right = num.substr(len - m, m);
    return {left, right};
}

// Function to pad a number with zeros
string padZeros(const string& num, int count) {
    string result = num;
    result.insert(result.begin(), count, '0');
    return result;
}

// Function to perform Karatsuba multiplication
string karatsuba(const string& x, const string& y) {
    if (x.length() == 1 || y.length() == 1) {
        // Base case: Single-digit multiplication
        int result = stoi(x) * stoi(y);
        return to_string(result);
    }

    int n = max(x.length(), y.length());
    int m = ceil(n / 2);

    // Divide x and y into two halves
    auto [a, b] = split(x, m);
    auto [c, d] = split(y, m);

    // Recursively compute three products
    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string adbc = karatsuba(to_string(stoi(a) + stoi(b)), to_string(stoi(c) + stoi(d))) - ac - bd;

    // Combine the results to obtain the final product
    string result = ac + padZeros(adbc, m) + bd;
    return result;
}

int main() {
    // Example usage
    string x = "1234";
    string y = "5678";

    cout << "Number 1: " << x << endl;
    cout << "Number 2: " << y << endl;

    string result = karatsuba(x, y);

    cout << "Product: " << result << endl;

    return 0;
}
