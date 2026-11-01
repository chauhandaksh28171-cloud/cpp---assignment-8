// Write a program to demonstrate function overloading (compile-time polymorphism).
// Create a class Calculator with overloaded functions add (int, int) and add (double,
// double) to perform addition.
#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int first, int second) const {
        return first + second;
    }

    double add(double first, double second) const {
        return first + second;
    }
};

int main() {
    Calculator calculator;

    cout << "Integer addition: " << calculator.add(10, 20) << '\n';
    cout << "Double addition: " << calculator.add(2.5, 3.7) << '\n';

    return 0;
}
