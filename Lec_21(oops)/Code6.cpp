// ============================================================
// Lec 21 - OOP in C++
// Topic: Polymorphism
//        -> Function Overloading  (Compile-time / Static)
//        -> Function Overriding   (Run-time / Dynamic)
//        -> Virtual Function
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------
// POLYMORPHISM
// ----------------------------
// "Many forms" - same name, different behavior.
//
// COMPILE-TIME (Static) Polymorphism:
//   -> Function Overloading: same function name, different parameters
//   -> Operator Overloading
//
// RUN-TIME (Dynamic) Polymorphism:
//   -> Function Overriding (via virtual functions + base class pointer)

// ==========================================
// 1. FUNCTION OVERLOADING
// ==========================================
// Same function name, different number or types of parameters.
// Resolved at COMPILE TIME.

class Calculator {
public:
    int add(int a, int b) {
        cout << "[int+int] ";
        return a + b;
    }

    double add(double a, double b) {
        cout << "[double+double] ";
        return a + b;
    }

    int add(int a, int b, int c) {      // 3 arguments
        cout << "[int+int+int] ";
        return a + b + c;
    }
};

// ==========================================
// 2. FUNCTION OVERRIDING + VIRTUAL FUNCTION
// ==========================================
// Child class redefines a method of the parent class.
// WITHOUT virtual: base pointer calls BASE version (early binding).
// WITH    virtual: base pointer calls DERIVED version (late binding).

class Shape {
public:
    // Without 'virtual' -> no runtime polymorphism
    void drawWithout() {
        cout << "Shape::drawWithout()" << endl;
    }

    // WITH 'virtual' -> enables runtime polymorphism
    virtual void draw() {
        cout << "Shape::draw()" << endl;
    }
};

class Circle : public Shape {
public:
    void drawWithout() {          // overrides, but base pointer won't call this
        cout << "Circle::drawWithout()" << endl;
    }

    void draw() override {        // 'override' keyword catches typos at compile time
        cout << "Circle::draw()" << endl;
    }
};

class Triangle : public Shape {
public:
    void drawWithout() {
        cout << "Triangle::drawWithout()" << endl;
    }

    void draw() override {
        cout << "Triangle::draw()" << endl;
    }
};

int main() {
    // ---- Function Overloading ----
    cout << "=== Function Overloading ===" << endl;
    Calculator calc;
    cout << calc.add(3, 4)          << endl;   // int version
    cout << calc.add(1.5, 2.5)      << endl;   // double version
    cout << calc.add(1, 2, 3)       << endl;   // 3-arg version

    cout << endl;

    // ---- Function Overriding WITHOUT virtual ----
    cout << "=== Overriding WITHOUT virtual ===" << endl;
    Shape* sp1 = new Circle();
    sp1->drawWithout();    // calls Shape::drawWithout() -> NOT polymorphic!

    cout << endl;

    // ---- Function Overriding WITH virtual ----
    cout << "=== Overriding WITH virtual ===" << endl;
    Shape* shapes[3];
    shapes[0] = new Shape();
    shapes[1] = new Circle();
    shapes[2] = new Triangle();

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();   // calls correct version at RUNTIME
    }

    // cleanup
    delete sp1;
    for (int i = 0; i < 3; i++) delete shapes[i];

    return 0;
}

/*
Output:
=== Function Overloading ===
[int+int] 7
[double+double] 4
[int+int+int] 6

=== Overriding WITHOUT virtual ===
Shape::drawWithout()     <- base version called, NOT Circle's

=== Overriding WITH virtual ===
Shape::draw()
Circle::draw()           <- correct derived version called
Triangle::draw()         <- correct derived version called
*/
