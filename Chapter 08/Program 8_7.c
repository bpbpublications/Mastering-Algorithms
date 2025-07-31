#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int GRID_SIZE = 10; // Change the grid size as needed
// Structure to represent a word in the crossword
struct Word {
    string text;
    int row, col;
    bool isHorizontal;
    Word(string t, int r, int c, bool h) : text(t), row(r), col(c), isHorizontal(h) {}
};
// Function to check if a word can be placed horizontally at the given position
bool canPlaceHorizontal(const vector<string>& grid, const string& word, int row, int col) {
    if (col + word.length() > GRID_SIZE) return false; // Check if word exceeds grid boundary
    for (int i = 0; i < word.length(); ++i) {
        if (grid[row][col + i] != '-' && grid[row][col + i] != word[i]) {
            return false; // Check for conflicting letters
        }
    }
    return true;
}
// Function to check if a word can be placed vertically at the given position
bool canPlaceVertical(const vector<string>& grid, const string& word, int row, int col) {
    if (row + word.length() > GRID_SIZE) return false; // Check if word exceeds grid boundary
    for (int i = 0; i < word.length(); ++i) {
        if (grid[row + i][col] != '-' && grid[row + i][col] != word[i]) {
            return false; // Check for conflicting letters
        }
    }
    return true;
}
// Function to place a word horizontally at the given position
void placeHorizontal(vector<string>& grid, const string& word, int row, int col) {
    for (int i = 0; i < word.length(); ++i) {
        grid[row][col + i] = word[i];
    }
}
// Function to place a word vertically at the given position
void placeVertical(vector<string>& grid, const string& word, int row, int col) {
    for (int i = 0; i < word.length(); ++i) {
        grid[row + i][col] = word[i];
    }
}
// Function to solve the crossword puzzle using backtracking
bool solveCrossword(vector<string>& grid, const vector<string>& words, int index) {
    if (index == words.size()) return true; // Base case: all words are placed
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grid[i][j] == '-' || grid[i][j] == words[index][0]) {
                if (canPlaceHorizontal(grid, words[index], i, j)) {
                    vector<string> tempGrid = grid;
                    placeHorizontal(tempGrid, words[index], i, j);
                    if (solveCrossword(tempGrid, words, index + 1)) {
                        grid = tempGrid;
                        return true;
                    }
                }
                if (canPlaceVertical(grid, words[index], i, j)) {
                    vector<string> tempGrid = grid;
                    placeVertical(tempGrid, words[index], i, j);
                    if (solveCrossword(tempGrid, words, index + 1)) {
                        grid = tempGrid;
                        return true;
                    }
                }
            }
        }
    }
    return false; // No solution found
}
// Function to display the crossword grid
void displayCrosswordGrid(const vector<string>& grid) {
    for (const string& row : grid) {
        cout << row << endl;
    }
}

int main() {
    vector<string> words = {"HELLO", "WORLD", "CROSSWORD", "PUZZLE"}; // Words to place in the crossword
    sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.length() > b.length(); }); // Sort words by length
    vector<string> grid(GRID_SIZE, string(GRID_SIZE, '-')); // Initialize the crossword grid with dashes
    if (solveCrossword(grid, words, 0)) {
        cout << "Crossword puzzle solved:" << endl;
        displayCrosswordGrid(grid);
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
