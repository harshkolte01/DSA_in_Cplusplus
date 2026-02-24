// ============================================================
// Lec 21 - OOP in C++
// Topic: Inheritance + Modes of Inheritance + Types of Inheritance
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------
// INHERITANCE
// ----------------------------
// Child class (derived) inherits properties & methods of Parent class (base).
// Promotes code reuse.
// Syntax: class Child : mode Parent { ... };
//
// MODE OF INHERITANCE:
//   public    -> public members stay public, protected stay protected
//   protected -> public & protected both become protected
//   private   -> public & protected both become private
//   (Most common: public inheritance)
//
// TYPES OF INHERITANCE:
//   1. Single        : one parent, one child
//   2. Multilevel    : A -> B -> C (chain)
//   3. Multiple      : child has two or more parents
//   4. Hierarchical  : one parent, many children
//   5. Hybrid        : combination of above types

// ==========================================
// 1. SINGLE INHERITANCE
// ==========================================
class Animal {
public:
    string name;

    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {   // Dog inherits Animal
public:
    void bark() {
        cout << name << " says: Woof!" << endl;
    }
};

// ==========================================
// 2. MULTILEVEL INHERITANCE  (A -> B -> C)
// ==========================================
class Vehicle {
public:
    void start() { cout << "Vehicle started." << endl; }
};

class Car : public Vehicle {
public:
    void drive() { cout << "Car is driving." << endl; }
};

class ElectricCar : public Car {    // inherits Car AND Vehicle
public:
    void charge() { cout << "Electric car is charging." << endl; }
};

// ==========================================
// 3. MULTIPLE INHERITANCE (two parents)
// ==========================================
class Flyable {
public:
    void fly() { cout << "Can fly!" << endl; }
};

class Swimmable {
public:
    void swim() { cout << "Can swim!" << endl; }
};

class Duck : public Flyable, public Swimmable {  // two parents
public:
    void quack() { cout << "Quack!" << endl; }
};

// ==========================================
// 4. HIERARCHICAL INHERITANCE (one parent, many children)
// ==========================================
class Shape {
public:
    void describe() { cout << "I am a Shape." << endl; }
};

class Circle : public Shape {
public:
    void draw() { cout << "Drawing Circle." << endl; }
};

class Rectangle : public Shape {
public:
    void draw() { cout << "Drawing Rectangle." << endl; }
};

// ==========================================
// PROTECTED MODE inheritance demo
// ==========================================
class Base {
public:
    int pub  = 1;   // public
protected:
    int prot = 2;   // protected
private:
    int priv = 3;   // private - NEVER inherited
};

class PublicChild : public Base {
    // pub  -> public,    prot -> protected,  priv -> NOT accessible
public:
    void show() { cout << "pub=" << pub << " prot=" << prot << endl; }
};

class ProtectedChild : protected Base {
    // pub  -> protected, prot -> protected,  priv -> NOT accessible
public:
    void show() { cout << "pub=" << pub << " prot=" << prot << endl; }
};

// ==========================================
// MAIN
// ==========================================
int main() {
    cout << "=== Single Inheritance ===" << endl;
    Dog d;
    d.name = "Bruno";
    d.eat();
    d.bark();

    cout << "\n=== Multilevel Inheritance ===" << endl;
    ElectricCar ec;
    ec.start();   // from Vehicle
    ec.drive();   // from Car
    ec.charge();  // own

    cout << "\n=== Multiple Inheritance ===" << endl;
    Duck duck;
    duck.fly();
    duck.swim();
    duck.quack();

    cout << "\n=== Hierarchical Inheritance ===" << endl;
    Circle c;  c.describe(); c.draw();
    Rectangle r; r.describe(); r.draw();

    cout << "\n=== Mode of Inheritance ===" << endl;
    PublicChild pc;
    pc.show();
    // pc.pub is accessible (still public)
    cout << "pc.pub = " << pc.pub << endl;

    ProtectedChild ptc;
    ptc.show();
    // ptc.pub is NOT accessible here (became protected)

    return 0;
}

/*
Output:
=== Single Inheritance ===
Bruno is eating.
Bruno says: Woof!

=== Multilevel Inheritance ===
Vehicle started.
Car is driving.
Electric car is charging.

=== Multiple Inheritance ===
Can fly!
Can swim!
Quack!

=== Hierarchical Inheritance ===
I am a Shape.
Drawing Circle.
I am a Shape.
Drawing Rectangle.

=== Mode of Inheritance ===
pub=1 prot=2
pc.pub = 1
pub=1 prot=2
*/
