# Lab Sheet-08 — Functions and OOPs Concepts in C++

**Course:** BCA I Semester  |  **Session:** 2026–2027

## Programs

Each question below is reproduced from the supplied PDF, followed by its solution. Individual source files are available in the `programs/` folder.

**Compile and run (C++17):**
```bash
g++ -std=c++17 programs/01_prime_number.cpp -o program
./program
```

Run the same command with the required source filename for each program.

**Note:** The PDF says “bubble shot technique”; the intended standard algorithm is Bubble Sort. Binary search input must be in ascending order. The diagonal-sum program adds both diagonals of a square matrix and counts the middle element only once.

## Question 1

Write a C++ function to find a prime number.

**Answer — `01_prime_number.cpp`**

```cpp
// Write a C++ function to find a prime number.
#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number < 2) return false;

    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) return false;
    }
    return true;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
        cout << number << " is a prime number.\n";
    else
        cout << number << " is not a prime number.\n";

    return 0;
}
```

## Question 2

Write a C++ function to print the Fibonacci series.

**Answer — `02_fibonacci_series.cpp`**

```cpp
// Write a C++ function to print the Fibonacci series.
#include <iostream>
using namespace std;

void printFibonacci(int terms) {
    long long first = 0, second = 1;

    for (int i = 0; i < terms; ++i) {
        cout << first << " ";
        long long next = first + second;
        first = second;
        second = next;
    }
    cout << '\n';
}

int main() {
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;

    if (terms < 0) {
        cout << "Number of terms cannot be negative.\n";
        return 1;
    }

    printFibonacci(terms);
    return 0;
}
```

## Question 3

Write a C++ function to apply the bubble shot technique on an array.

**Answer — `03_bubble_sort_array.cpp`**

```cpp
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
```

## Question 4

Write a C++ function to copy a string from another string.

**Answer — `04_copy_string.cpp`**

```cpp
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
```

## Question 5

Write a C++ function to find out the number of words in a string.

**Answer — `05_count_words_string.cpp`**

```cpp
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
```

## Question 6

Write a C++ function to search an element using a binary search technique.

**Answer — `06_binary_search.cpp`**

```cpp
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
```

## Question 7

Write a C++ function to find the sum of two matrix.

**Answer — `07_sum_of_two_matrices.cpp`**

```cpp
// Write a C++ function to find the sum of two matrix.
#include <iostream>
#include <vector>
using namespace std;

void addMatrices(const vector<vector<int>>& first,
                 const vector<vector<int>>& second,
                 vector<vector<int>>& result) {
    int rows = static_cast<int>(first.size());
    int columns = static_cast<int>(first[0].size());

    result.assign(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            result[i][j] = first[i][j] + second[i][j];
}

int main() {
    int rows, columns;
    cout << "Enter rows and columns: ";
    cin >> rows >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Rows and columns must be positive.\n";
        return 1;
    }

    vector<vector<int>> first(rows, vector<int>(columns));
    vector<vector<int>> second(rows, vector<int>(columns));
    vector<vector<int>> result;

    cout << "Enter first matrix:\n";
    for (auto& row : first)
        for (int& value : row) cin >> value;

    cout << "Enter second matrix:\n";
    for (auto& row : second)
        for (int& value : row) cin >> value;

    addMatrices(first, second, result);

    cout << "Sum of matrices:\n";
    for (const auto& row : result) {
        for (int value : row) cout << value << " ";
        cout << '\n';
    }

    return 0;
}
```

## Question 8

Write a C++ function to find out the sum of diagonal numbers in matrix.

**Answer — `08_sum_of_diagonal_elements.cpp`**

```cpp
// Write a C++ function to find out the sum of diagonal numbers in matrix.
#include <iostream>
#include <vector>
using namespace std;

// Adds both main and secondary diagonals; the center is counted once.
int diagonalSum(const vector<vector<int>>& matrix) {
    int size = static_cast<int>(matrix.size());
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += matrix[i][i];
        if (i != size - 1 - i)
            sum += matrix[i][size - 1 - i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter order of square matrix: ";
    cin >> size;

    if (size <= 0) {
        cout << "Order must be positive.\n";
        return 1;
    }

    vector<vector<int>> matrix(size, vector<int>(size));
    cout << "Enter matrix elements:\n";
    for (auto& row : matrix)
        for (int& value : row) cin >> value;

    cout << "Sum of diagonal elements: " << diagonalSum(matrix) << '\n';
    return 0;
}
```

## Question 9

Write a C++ function to swap two numbers using call-by-reference properties.

**Answer — `09_swap_call_by_reference.cpp`**

```cpp
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
```

## Question 10

Write a program to define a class Student with data members name, roll_no, and marks.
Use member functions to input and display the details of the student.

**Answer — `10_student_class.cpp`**

```cpp
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
```

## Question 11

Write a program to define a class Car with members brand and price.
Create multiple objects of the class and display their information.

**Answer — `11_car_class_objects.cpp`**

```cpp
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
```

## Question 12

Write a program to demonstrate encapsulation using a class Bank Account.
Keep balance as a private data member and provide public functions deposit () and
withdraw () to modify it safely.

**Answer — `12_bank_account_encapsulation.cpp`**

```cpp
// Write a program to demonstrate encapsulation using a class Bank Account.
// Keep balance as a private data member and provide public functions deposit () and
// withdraw () to modify it safely.
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance = 0.0)
        : balance(initialBalance >= 0 ? initialBalance : 0.0) {}

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Deposit amount must be positive.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0)
            cout << "Withdrawal amount must be positive.\n";
        else if (amount > balance)
            cout << "Insufficient balance.\n";
        else
            balance -= amount;
    }

    void displayBalance() const {
        cout << "Current balance: " << balance << '\n';
    }
};

int main() {
    double initialBalance, depositAmount, withdrawAmount;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(initialBalance);

    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    account.displayBalance();
    return 0;
}
```

## Question 13

Write a program to demonstrate single inheritance.
Create a base class Person with name and age, and a derived class Student with marks.
Display all details using functions.

**Answer — `13_single_inheritance.cpp`**

```cpp
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
```

## Question 14

Write a program to demonstrate function overloading (compile-time polymorphism).
Create a class Calculator with overloaded functions add (int, int) and add (double,
double) to perform addition.

**Answer — `14_function_overloading.cpp`**

```cpp
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
```

## Question 15

Write a program to demonstrate abstraction using an abstract class Shape.
Define a pure virtual function area (), and create derived classes Circle and Rectangle
to calculate and display their areas.

**Answer — `15_abstraction_shape.cpp`**

```cpp
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
```

## Submission notes

- There are 15 independent `.cpp` programs in `programs/`.
- Use a C++17-compatible compiler.
- Enter input when prompted by each program.
- Check that the binary-search array is sorted in ascending order before searching.