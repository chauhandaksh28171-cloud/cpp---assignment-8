// Write a C++ function to find out the sum of diagonal numbers in matrix.
#include <iostream>
#include <vector>
using namespace std;

// Adds both main and secondary diagonals; the center is counted once.
int diagonalSum(const vector<vector<int>>& matrix) {
    int size = static_cast<int>(matrix.size());
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += matrix[i][i];
        if (i != size - 1 - i)
            sum += matrix[i][size - 1 - i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter order of square matrix: ";
    cin >> size;

    if (size <= 0) {
        cout << "Order must be positive.\n";
        return 1;
    }

    vector<vector<int>> matrix(size, vector<int>(size));
    cout << "Enter matrix elements:\n";
    for (auto& row : matrix)
        for (int& value : row) cin >> value;

    cout << "Sum of diagonal elements: " << diagonalSum(matrix) << '\n';
    return 0;
}
