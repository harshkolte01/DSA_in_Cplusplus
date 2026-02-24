// ============================================================
// Lec 21 - OOP in C++
// Topic: this Pointer + Copy Constructor + Shallow vs Deep Copy
// ============================================================

#include <iostream>
#include <cstring>  // for strcpy, strlen
using namespace std;

// ----------------------------
// this POINTER
// ----------------------------
// 'this' is a pointer that holds the address of the current object.
// Useful when local variable names clash with member variable names.

class Box {
private:
    int length;
    int width;

public:
    // Without 'this', we'd need different parameter names
    Box(int length, int width) {
        this->length = length;  // this->length = member, length = parameter
        this->width  = width;
    }

    // 'this' can also be used to return the current object (method chaining)
    Box& setLength(int length) {
        this->length = length;
        return *this;  // return current object by reference
    }

    Box& setWidth(int width) {
        this->width = width;
        return *this;
    }

    void show() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

// ----------------------------
// SHALLOW COPY vs DEEP COPY
// ----------------------------
// Shallow Copy: copies pointer address -> both objects point to SAME memory
//               (default copy constructor does shallow copy)
// Deep Copy:    allocates NEW memory and copies the data
//               -> objects are truly independent

class ShallowExample {
public:
    int* data;

    ShallowExample(int val) {
        data  = new int(val);
    }

    // Default copy constructor = SHALLOW COPY (just copies pointer)
    // Both original and copy point to same memory!

    void show(const string& label) const {
        cout << label << " -> data address: " << data
             << ", value: " << *data << endl;
    }

    ~ShallowExample() {
        // Both objects would try to delete same memory -> CRASH (double free)
        // For demo, we skip delete here
    }
};

class DeepExample {
public:
    int* data;

    DeepExample(int val) {
        data  = new int(val);
    }

    // DEEP COPY CONSTRUCTOR - allocate new memory
    DeepExample(const DeepExample& other) {
        data  = new int(*other.data);  // NEW allocation, copy VALUE
        cout << "[Deep Copy Constructor called]" << endl;
    }

    void show(const string& label) const {
        cout << label << " -> data address: " << data
             << ", value: " << *data << endl;
    }

    ~DeepExample() {
        delete data;
    }
};

int main() {
    // ---- this pointer demo ----
    cout << "=== this Pointer ===" << endl;
    Box b1(10, 5);
    b1.show();

    // Method chaining using 'this'
    b1.setLength(20).setWidth(8);
    b1.show();

    cout << endl;

    // ---- Shallow Copy ----
    cout << "=== Shallow Copy ===" << endl;
    ShallowExample s1(42);
    ShallowExample s2 = s1;  // default copy -> shallow

    s1.show("s1");
    s2.show("s2");
    cout << "Same address? " << (s1.data == s2.data ? "YES (problem!)" : "NO") << endl;

    cout << endl;

    // ---- Deep Copy ----
    cout << "=== Deep Copy ===" << endl;
    DeepExample d1(100);
    DeepExample d2 = d1;  // calls our custom deep copy constructor

    d1.show("d1");
    d2.show("d2");
    cout << "Same address? " << (d1.data == d2.data ? "YES" : "NO (independent - correct!)") << endl;

    // Modify d2, d1 should NOT change
    *d2.data = 999;
    cout << "After modifying d2:" << endl;
    d1.show("d1");
    d2.show("d2");

    return 0;
}

/*
Output:
=== this Pointer ===
Length: 10, Width: 5
Length: 20, Width: 8

=== Shallow Copy ===
s1 -> data address: 0x... , value: 42
s2 -> data address: 0x... , value: 42
Same address? YES (problem!)

=== Deep Copy ===
[Deep Copy Constructor called]
d1 -> data address: 0x...  , value: 100
d2 -> data address: 0x...  , value: 100
Same address? NO (independent - correct!)
After modifying d2:
d1 -> data address: 0x...  , value: 100
d2 -> data address: 0x...  , value: 999
*/
