// Write a C++ function to search an element using a binary search technique.
#include <iostream>
#include <vector>
using namespace std;

// Binary search requires the array to be sorted in ascending order.
int binarySearch(const vector<int>& numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target) return middle;
        if (numbers[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    if (size < 0) {
        cout << "Array size cannot be negative.\n";
        return 1;
    }

    vector<int> numbers(size);
    cout << "Enter " << size << " elements in ascending order: ";
    for (int& number : numbers) cin >> number;

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int index = binarySearch(numbers, target);
    if (index == -1)
        cout << "Element not found.\n";
    else
        cout << "Element found at index " << index << ".\n";

    return 0;
}
