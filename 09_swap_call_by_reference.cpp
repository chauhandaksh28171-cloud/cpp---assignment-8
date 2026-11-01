// Write a C++ function to swap two numbers using call-by-reference properties.
#include <iostream>
#include <utility>
using namespace std;

void swapNumbers(int& first, int& second) {
    int temporary = first;
    first = second;
    second = temporary;
}

int main() {
    int first, second;
    cout << "Enter two numbers: ";
    cin >> first >> second;

    swapNumbers(first, second);

    cout << "After swapping: " << first << " " << second << '\n';
    return 0;
}
