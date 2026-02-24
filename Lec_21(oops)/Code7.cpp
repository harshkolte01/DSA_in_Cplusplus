// ============================================================
// Lec 21 - OOP in C++
// Topic: Abstraction + Abstract Class + Static Keyword
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------
// ABSTRACTION
// ----------------------------
// Hiding complex implementation details, showing only essential features.
// In C++ this is achieved via:
//   1. Abstract classes (pure virtual functions)
//   2. Access specifiers (private hides implementation)

// ----------------------------
// ABSTRACT CLASS
// ----------------------------
// A class with at least one PURE VIRTUAL function (= 0).
// Cannot create objects of an abstract class directly.
// Forces all derived classes to implement the pure virtual function.

class Shape {   // Abstract class
public:
    // Pure virtual function -> makes class abstract
    virtual double area()      = 0;
    virtual double perimeter() = 0;

    // Can have a concrete (non-pure) function too
    void describe() {
        cout << "Area     = " << area()      << endl;
        cout << "Perimeter= " << perimeter() << endl;
    }
};

// Shape s;  -> ERROR! Cannot instantiate abstract class

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;
public:
    Circle(double r) : radius(r) {}

    double area()      override { return PI * radius * radius; }
    double perimeter() override { return 2 * PI * radius; }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area()      override { return length * width; }
    double perimeter() override { return 2 * (length + width); }
};

// ----------------------------
// STATIC KEYWORD
// ----------------------------
// static member variable : shared across ALL objects of the class
//                          only ONE copy exists in memory
// static member function : can be called without an object
//                          can only access static members

class Counter {
public:
    static int count;   // declaration (shared by all objects)

    Counter() {
        count++;   // every new object increments shared count
        cout << "Object created. Total objects: " << count << endl;
    }

    ~Counter() {
        count--;
        cout << "Object destroyed. Total objects: " << count << endl;
    }

    // static function - no 'this' pointer, called on class
    static int getCount() {
        return count;
    }
};

// DEFINITION of static member (required outside class)
int Counter::count = 0;

int main() {
    // ---- Abstraction + Abstract Class ----
    cout << "=== Abstract Class ===" << endl;

    Shape* s1 = new Circle(5);
    cout << "Circle:" << endl;
    s1->describe();

    Shape* s2 = new Rectangle(4, 6);
    cout << "Rectangle:" << endl;
    s2->describe();

    delete s1;
    delete s2;

    cout << endl;

    // ---- Static Keyword ----
    cout << "=== Static Keyword ===" << endl;

    // Call static function without any object
    cout << "Before any object. Count = " << Counter::getCount() << endl;

    Counter* c1 = new Counter();
    Counter* c2 = new Counter();
    Counter* c3 = new Counter();

    cout << "Count via class  : " << Counter::count    << endl;
    cout << "Count via function: " << Counter::getCount() << endl;

    delete c1;
    delete c3;

    cout << "Remaining objects: " << Counter::getCount() << endl;

    delete c2;

    return 0;
}

/*
Output:
=== Abstract Class ===
Circle:
Area     = 78.5397
Perimeter= 31.4159
Rectangle:
Area     = 24
Perimeter= 20

=== Static Keyword ===
Before any object. Count = 0
Object created. Total objects: 1
Object created. Total objects: 2
Object created. Total objects: 3
Count via class  : 3
Count via function: 3
Object destroyed. Total objects: 2
Object destroyed. Total objects: 1
Remaining objects: 1
Object destroyed. Total objects: 0
*/
