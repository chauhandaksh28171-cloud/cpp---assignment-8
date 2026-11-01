// Write a C++ function to find out the number of words in a string.
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countWords(const string& text) {
    istringstream input(text);
    string word;
    int count = 0;

    while (input >> word) ++count;
    return count;
}

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    cout << "Number of words: " << countWords(text) << '\n';
    return 0;
}
