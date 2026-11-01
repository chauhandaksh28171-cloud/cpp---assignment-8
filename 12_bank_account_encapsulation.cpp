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
