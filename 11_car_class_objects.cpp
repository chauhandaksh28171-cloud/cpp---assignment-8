// Write a program to define a class Car with members brand and price.
// Create multiple objects of the class and display their information.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
public:
    string brand;
    double price;

    void display() const {
        cout << "Brand: " << brand << ", Price: " << price << '\n';
    }
};

int main() {
    int count;
    cout << "Enter number of cars: ";
    cin >> count;

    if (count <= 0) {
        cout << "Number of cars must be positive.\n";
        return 1;
    }

    vector<Car> cars(count);
    for (int i = 0; i < count; ++i) {
        cout << "Enter brand and price for car " << i + 1 << ": ";
        cin >> cars[i].brand >> cars[i].price;
    }

    cout << "Car details:\n";
    for (const Car& car : cars) car.display();

    return 0;
}
