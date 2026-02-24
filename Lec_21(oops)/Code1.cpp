// ============================================================
// Lec 21 - OOP in C++
// Topic: Class & Object + Access Specifiers
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------
// CLASS & OBJECT
// ----------------------------
// A class is a blueprint / template.
// An object is a real-world instance of that class.

// Access Specifiers:
//   public    -> accessible from anywhere
//   private   -> accessible only inside the class
//   protected -> accessible inside class + derived classes

class Student {
    // private by default in class
private:
    int rollNo;   // only accessible inside this class

public:
    string name;  // accessible from outside
    int age;

    // Member function (method) - defined inside class
    void showInfo() {
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age  << endl;
        cout << "RollNo : " << rollNo << endl;
    }

    // setter for private member
    void setRollNo(int r) {
        rollNo = r;
    }
};

// Member function defined OUTSIDE the class using :: (scope resolution)
// (just showing syntax - showInfo is already inside above)

int main() {
    // Creating an object of class Student
    Student s1;

    // Accessing public members directly
    s1.name = "Alice";
    s1.age  = 20;

    // Cannot do: s1.rollNo = 5;  -> ERROR (private)
    s1.setRollNo(101);  // use setter for private member

    s1.showInfo();

    cout << endl;

    // Another object
    Student s2;
    s2.name = "Bob";
    s2.age  = 22;
    s2.setRollNo(102);
    s2.showInfo();

    return 0;
}

/*
Output:
Name   : Alice
Age    : 20
RollNo : 101

Name   : Bob
Age    : 22
RollNo : 102
*/
