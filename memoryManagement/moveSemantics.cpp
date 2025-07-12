#pragma once
#include <stdlib.h>
#include <iostream>

namespace kaleem::movesemantics {


int add(int x, int y) { return x+y; }

// Accepts an lvalue refernce only
void Print(int& x) {
    std::cout << "Print(int& x)\n";
}

// Accepts an rvalue reference only
void Print(int&& x) {
    std::cout << "Print(int&& x)\n";
}

// Accepts both lvalue and rvalue references
void Print(const int& x) {
    std::cout << "Print(const int& x)\n";
}

class Integer {
private:
    int* m_ptr;
public:
    Integer() : m_ptr{new int{0}} {
        std::cout << "Integer()\n";
    }
    Integer(const Integer& other) { // Copy Ctor
        std::cout << "Integer(const Integer& other)\n";
        m_ptr = new int{*other.m_ptr};
    }
    Integer(Integer&& other) { // Move Ctor
        std::cout << "Integer(Integer&& other)\n";
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }
    Integer(int val_) : m_ptr{new int{val_}} {
        std::cout << "Integer(int val_)\n";
    }
    int getValue() const {
        return *m_ptr;
    }
    bool setVal(int val_) {
        *m_ptr = val_;
        return true;
    }
    ~Integer() {
        std::cout << "~Integer()\n";
        delete m_ptr;
    }
};

Integer Add(const Integer& x, const Integer& y) {
    Integer ret;
    ret.setVal(x.getValue() + y.getValue());
    return ret;
}


}




int main() {
/*
Lvalue: Named variable, can be assgined another value,
int x;

Rvalue: temporary
int x = 5; 5->rvalue

expressions can return an lvalue, or an rvalue
rvalue are temporaries, and cannot persist beyond the expression
lvalue persist beyond the expression

we can create a reference to an lval
we can also create reference to an rvalue 
rvalue references have been introduced in C++ to implement move semantics
create using &&
rval ref always bind to temporaries
lval ref always binds to lvalues
const lval ref can bind to an rval reference

int &&r1 = 10; 
int &&r2 = add(5, 7);
int &&r3 = 7+3;

int add(int x, int y) {
    return x+y;
} // return rval


int& apply(int& x) {
    x = x*x;
    return x;
} // returns rval


Move Semantics:
Dynamic memory -> create deep copy else  Shallow Copy

Copy is implemented throgh a copy ctor
It is wasteful for a deep copy to be created out of a temporary, we can just swap pointers.
We can simply move instead of copying.
Ctor needs to bind to the temporary


Rule of 5:
Some classes may own a resource
Such resources maybe acquired in the Ctor
Subsequently, we need to decide the action in case such classes are copied/moved/destroyed.

If a class has ownership semantics then we must provide a user defined:
1. Copy Ctor
2. Copy Assignment Operator
3. Move Ctor
4. Move Assignment Operator
5. Destructor

Modern compilers will do RTO
Copy/Move Elision will be there

std::move -> used with lvalues, forces the compiler to use move operations instead of copy operations
*/

    using namespace kaleem::movesemantics;

    Integer a{2};
    Integer b{4};
    a.setVal(Add(a, b).getValue());



}
