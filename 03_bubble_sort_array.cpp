// Write a C++ function to apply the bubble shot technique on an array.
// The intended technique is Bubble Sort.
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void bubbleSort(vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        bool swapped = false;

        for (size_t j = 0; j + 1 < numbers.size() - i; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
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
    cout << "Enter " << size << " elements: ";
    for (int& number : numbers) cin >> number;

    bubbleSort(numbers);

    cout << "Sorted array: ";
    for (int number : numbers) cout << number << " ";
    cout << '\n';

    return 0;
}
