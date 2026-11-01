// Write a program to demonstrate single inheritance.
// Create a base class Person with name and age, and a derived class Student with marks.
// Display all details using functions.
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age{};

public:
    void inputPerson() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    }

    void displayPerson() const {
        cout << "Name: " << name << "\nAge: " << age << '\n';
    }
};

class Student : public Person {
private:
    float marks{};

public:
    void inputStudent() {
        inputPerson();
        cout << "Enter marks: ";
        cin >> marks;
    }

    void displayStudent() const {
        displayPerson();
        cout << "Marks: " << marks << '\n';
    }
};

int main() {
    Student student;
    student.inputStudent();
    student.displayStudent();
    return 0;
}
