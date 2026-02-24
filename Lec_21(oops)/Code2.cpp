// ============================================================
// Lec 21 - OOP in C++
// Topic: Encapsulation + Constructors
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------
// ENCAPSULATION
// ----------------------------
// Wrapping data (variables) and methods (functions) together into one unit.
// Private data is hidden from outside; access is controlled via public methods.
// This is also called DATA HIDING.

// ----------------------------
// CONSTRUCTOR
// ----------------------------
// Special member function called AUTOMATICALLY when an object is created.
// Same name as the class. No return type.
// Types:
//   1. Default Constructor    - no parameters
//   2. Parameterized Constructor - takes arguments
//   3. Constructor Overloading - multiple constructors (different params)

class BankAccount {
private:
    string owner;
    double balance;   // hidden from outside

public:
    // ---- 1. Default Constructor ----
    BankAccount() {
        owner   = "Unknown";
        balance = 0.0;
        cout << "[Default Constructor] Account created for: " << owner << endl;
    }

    // ---- 2. Parameterized Constructor ----
    BankAccount(string name, double initialBalance) {
        owner   = name;
        balance = initialBalance;
        cout << "[Param Constructor] Account created for: " << owner << endl;
    }

    // Encapsulation: controlled access via public methods
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!" << endl;
    }

    // Getter (read-only access to private data)
    double getBalance() const {
        return balance;
    }

    void showAccount() const {
        cout << "Owner  : " << owner   << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Default constructor called
    BankAccount acc1;
    acc1.deposit(1000);
    acc1.showAccount();

    cout << endl;

    // Parameterized constructor called
    BankAccount acc2("Alice", 5000.0);
    acc2.deposit(2000);
    acc2.withdraw(1500);
    acc2.showAccount();

    // Cannot access private member directly:
    // acc2.balance = 100;  -> ERROR (encapsulation enforced)

    return 0;
}

/*
Output:
[Default Constructor] Account created for: Unknown
Owner  : Unknown
Balance: 1000

[Param Constructor] Account created for: Alice
Owner  : Alice
Balance: 5500
*/
