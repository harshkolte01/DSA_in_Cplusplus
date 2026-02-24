// ============================================================
// Lec 21 - OOP in C++
// Topic: Destructor
// ============================================================

#include <iostream>
using namespace std;

// ----------------------------
// DESTRUCTOR
// ----------------------------
// Called AUTOMATICALLY when an object goes out of scope or is deleted.
// Same name as class but with a ~ prefix.
// No parameters, no return type.
// Used to FREE resources (memory, file handles, etc.)
// There can only be ONE destructor per class.

class Resource {
private:
    string name;
    int* data;  // dynamic memory to demonstrate cleanup

public:
    // Constructor - allocates resource
    Resource(string n, int val) {
        name = n;
        data = new int(val);
        cout << "[Constructor] " << name << " created, data = " << *data << endl;
    }

    // Copy Constructor (deep copy)
    Resource(const Resource& other) {
        name = other.name + "_copy";
        data = new int(*other.data);
        cout << "[Copy Constructor] " << name << " created" << endl;
    }

    void show() const {
        cout << "Resource: " << name << ", data = " << *data << endl;
    }

    // Destructor - frees resource
    ~Resource() {
        cout << "[Destructor] " << name << " destroyed, freeing memory" << endl;
        delete data;  // free heap memory
        data = nullptr;
    }
};

void demo() {
    cout << "--- Entering demo() ---" << endl;
    Resource r1("File", 100);
    Resource r2("Socket", 200);
    r1.show();
    r2.show();
    cout << "--- Leaving demo() ---" << endl;
    // r2 destroyed first (LIFO), then r1
}

int main() {
    cout << "=== Object on stack (auto destruction) ===" << endl;
    demo();  // r1, r2 destructors called when demo() ends

    cout << endl;

    cout << "=== Object on heap (manual destruction) ===" << endl;
    Resource* ptr = new Resource("HeapObj", 999);
    ptr->show();
    delete ptr;  // MUST call delete to trigger destructor for heap objects
    ptr = nullptr;

    cout << endl;
    cout << "Main ends here." << endl;
    return 0;
}

/*
Output:
=== Object on stack (auto destruction) ===
--- Entering demo() ---
[Constructor] File created, data = 100
[Constructor] Socket created, data = 200
Resource: File, data = 100
Resource: Socket, data = 200
--- Leaving demo() ---
[Destructor] Socket destroyed, freeing memory
[Destructor] File destroyed, freeing memory

=== Object on heap (manual destruction) ===
[Constructor] HeapObj created, data = 999
Resource: HeapObj, data = 999
[Destructor] HeapObj destroyed, freeing memory

Main ends here.
*/
