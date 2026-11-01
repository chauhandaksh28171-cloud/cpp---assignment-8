// Write a program to demonstrate abstraction using an abstract class Shape.
// Define a pure virtual function area (), and create derived classes Circle and Rectangle
// to calculate and display their areas.
#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double radius) : radius(radius) {}

    double area() const override {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double area() const override {
        return length * width;
    }
};

int main() {
    double radius, length, width;
    cout << "Enter circle radius: ";
    cin >> radius;
    cout << "Enter rectangle length and width: ";
    cin >> length >> width;

    Circle circle(radius);
    Rectangle rectangle(length, width);

    cout << fixed << setprecision(2);
    cout << "Area of circle: " << circle.area() << '\n';
    cout << "Area of rectangle: " << rectangle.area() << '\n';

    return 0;
}
