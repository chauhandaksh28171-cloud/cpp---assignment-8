// Write a C++ function to print the Fibonacci series.
#include <iostream>
using namespace std;

void printFibonacci(int terms) {
    long long first = 0, second = 1;

    for (int i = 0; i < terms; ++i) {
        cout << first << " ";
        long long next = first + second;
        first = second;
        second = next;
    }
    cout << '\n';
}

int main() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;

    if (terms < 0) {
        cout << "Number of terms cannot be negative.\n";
        return 1;
    }

    printFibonacci(terms);
    return 0;
}
