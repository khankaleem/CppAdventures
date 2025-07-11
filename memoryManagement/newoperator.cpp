#pragma once
#include <stdlib.h>
#include <iostream>

namespace kaleem::newoperator {

struct X {
    int x;
    X() = default;
    X(int x_) : x{x_} {}
};

}


int main() {
/*
    new: operator
    type is already known, so compiler ascertains the size from the type
    constructs the object, and returns the pointer
    throws an exception on failure
*/
    // Variable
    auto* p = new kaleem::newoperator::X{100};
    std::cout << p->x << '\n';
    delete p;
    p = nullptr; // Avoid dangling pointer

    // 1-D Array
    p = new kaleem::newoperator::X[5]; // default constructor
    for (size_t i = 0; i < 5; i++) {
        std::cout << (p+i)->x << '\n';
    }
    delete []p;
    p = nullptr;

    // 2-D Array
    kaleem::newoperator::X* *q = new kaleem::newoperator::X* [3];
    q[0] = new kaleem::newoperator::X[3]{3,3,3};
    q[1] = new kaleem::newoperator::X[5]{5,5,5,5,5};
    q[2] = new kaleem::newoperator::X[7]{7,7,7,7,7,7,7};

    std::cout << q[0][0].x << '\n';
    std::cout << q[1][0].x << '\n';
    std::cout << q[2][0].x << '\n';
    delete []q[2];
    delete []q[1];
    delete []q[0];
    delete []q;
    q = nullptr;

}