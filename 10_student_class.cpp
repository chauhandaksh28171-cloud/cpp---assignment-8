// Write a program to define a class Student with data members name, roll_no, and marks.
// Use member functions to input and display the details of the student.
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student {
private:
    string name;
    int roll_no{};
    float marks{};

public:
    void input() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number and marks: ";
        cin >> roll_no >> marks;
    }

    void display() const {
        cout << "Name: " << name << "\nRoll number: " << roll_no
             << "\nMarks: " << marks << '\n';
    }
};

int main() {
    Student student;
    student.input();
    student.display();
    return 0;
}
