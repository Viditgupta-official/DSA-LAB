#include <iostream>
using namespace std;

// (a) Reverse Array
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// (b) Matrix Multiplication
void multiplyMatrices(int A[10][10], int B[10][10], int C[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// (c) Transpose Matrix
void transposeMatrix(int A[10][10], int B[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            B[j][i] = A[i][j];
        }
    }
}

int main() {
    // --- Reverse Array Demo ---
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Original Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    reverseArray(arr, 5);

    cout << "Reversed Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    // --- Matrix Multiplication Demo ---
    int A[10][10] = {{1, 2, 3}, {4, 5, 6}};
    int B[10][10] = {{7, 8}, {9, 10}, {11, 12}};
    int C[10][10];

    int m = 2, n = 3, p = 2; // A is 2x3, B is 3x2
    multiplyMatrices(A, B, C, m, n, p);

    cout << "\nMatrix Multiplication Result:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // --- Transpose Matrix Demo ---
    int T[10][10];
    transposeMatrix(A, T, m, n);

    cout << "\nTranspose of Matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}