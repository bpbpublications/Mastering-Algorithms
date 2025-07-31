#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<int>> strassenMatrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        // Base case: standard matrix multiplication for 1x1 matrices
        vector<vector<int>> result(1, vector<int>(1, 0));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    // Divide matrices into submatrices
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)), A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)), B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Compute products of submatrices using Strassen's formulas
    vector<vector<int>> P1 = strassenMatrixMultiply(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int>> P2 = strassenMatrixMultiply(addMatrices(A21, A22), B11);
    vector<vector<int>> P3 = strassenMatrixMultiply(A11, subtractMatrices(B12, B22));
    vector<vector<int>> P4 = strassenMatrixMultiply(A22, subtractMatrices(B21, B11));
    vector<vector<int>> P5 = strassenMatrixMultiply(addMatrices(A11, A12), B22);
    vector<vector<int>> P6 = strassenMatrixMultiply(subtractMatrices(A21, A11), addMatrices(B11, B12));
    vector<vector<int>> P7 = strassenMatrixMultiply(subtractMatrices(A12, A22), addMatrices(B21, B22));

    // Compute submatrices of the result
    vector<vector<int>> C11 = subtractMatrices(addMatrices(P1, P4), addMatrices(P5, P7));
    vector<vector<int>> C12 = addMatrices(P3, P5);
    vector<vector<int>> C21 = addMatrices(P2, P4);
    vector<vector<int>> C22 = addMatrices(subtractMatrices(P1, P2), addMatrices(P3, P6));

    // Construct the result matrix
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}

int main() {
    // Example usage
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "Matrix A:\n";
    for (const auto& row : A) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << "Matrix B:\n";
    for (const auto& row : B) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    vector<vector<int>> result = strassenMatrixMultiply(A, B);

    cout << "Resultant Matrix:\n";
    for (const auto& row : result) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
