// Write a C++ function to find the sum of two matrix.
#include <iostream>
#include <vector>
using namespace std;

void addMatrices(const vector<vector<int>>& first,
                 const vector<vector<int>>& second,
                 vector<vector<int>>& result) {
    int rows = static_cast<int>(first.size());
    int columns = static_cast<int>(first[0].size());

    result.assign(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            result[i][j] = first[i][j] + second[i][j];
}

int main() {
    int rows, columns;
    cout << "Enter rows and columns: ";
    cin >> rows >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Rows and columns must be positive.\n";
        return 1;
    }

    vector<vector<int>> first(rows, vector<int>(columns));
    vector<vector<int>> second(rows, vector<int>(columns));
    vector<vector<int>> result;

    cout << "Enter first matrix:\n";
    for (auto& row : first)
        for (int& value : row) cin >> value;

    cout << "Enter second matrix:\n";
    for (auto& row : second)
        for (int& value : row) cin >> value;

    addMatrices(first, second, result);

    cout << "Sum of matrices:\n";
    for (const auto& row : result) {
        for (int value : row) cout << value << " ";
        cout << '\n';
    }

    return 0;
}
