// Write a C++ function to copy a string from another string.
#include <iostream>
#include <string>
using namespace std;

string copyString(const string& source) {
    string destination;
    for (char character : source)
        destination += character;
    return destination;
}

int main() {
    string source;
    cout << "Enter a string: ";
    getline(cin, source);

    string destination = copyString(source);
    cout << "Copied string: " << destination << '\n';

    return 0;
}
