#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <set>
#include <stddef.h>

const int& max(const int& a, const int& b) {
    std::cout << "CALLED NON TEMPLATE FOR TWO ARGS\n";
    return a>b?a:b;
}

template<typename T>
const T& max(const T& a, const T& b) {
    std::cout << "CALLED TEMPLATE FOR TWO ARGS\n";
    return a>b?a:b;
}

template<typename T>
const T& max(const T& a, const T& b, const T& c) {
    std::cout << "CALLED TEMPLATE FOR THREE ARGS\n";
    return max(a, max(b,c));
}

int main() {
    ::max(10, 20);
    ::max(10.1, 20.1);
    ::max<>(10,2);//only templates should resolve the call
    ::max('a', 'b');
    ::max('a', 29);
    ::max<double>(10,20);
    ::max(109,20,100);
}