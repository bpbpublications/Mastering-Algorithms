#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool solveCryptarithmetic(vector<string>& words, string& resultWord) {
    string uniqueChars = "";
    for (string word : words) {
        for (char ch : word) {
            if (uniqueChars.find(ch) == string::npos)
                uniqueChars += ch;
        }
    }
    if (uniqueChars.size() > 10) return false; // Too many unique characters for 0-9 digits
    sort(uniqueChars.begin(), uniqueChars.end());
    vector<int> mapping;
    do {
        if (uniqueChars.size() > 1 && mapping[0] == 0) continue; // Leading zeros are not allowed
        int carry = 0, sum = 0;
        for (int i = resultWord.size() - 1; i >= 0; i--) {
            int digitSum = carry;
            for (string word : words) {
                if (word.size() > i)
                    digitSum += mapping[uniqueChars.find(word[i])];
            }
            carry = digitSum / 10;
            sum += (digitSum % 10) * pow(10, resultWord.size() - 1 - i);
        }
        if (carry == 0 && sum == 0) continue; // No leading zeros
        if (sum == 0) continue; // No leading zeros in result word
        int result = 0;
        for (char ch : resultWord)
            result = result * 10 + mapping[uniqueChars.find(ch)];
        if (sum == result) {
            for (char ch : uniqueChars)
                cout << ch << " = " << mapping[uniqueChars.find(ch)] << ", ";
            cout << endl;
            return true;
        }
    } while (next_permutation(mapping.begin(), mapping.end()));
    return false;
}
int main() {
    vector<string> words = {"TWO", "TWO"};
    string resultWord = "FOUR";
    vector<int> mapping;
    for (int i = 0; i < 10; i++)
        mapping.push_back(i);
    if (!solveCryptarithmetic(words, resultWord))
        cout << "No solution found!" << endl;
        return 0;
}
