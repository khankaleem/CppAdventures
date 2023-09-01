#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <set>
#include <stddef.h>


template<typename T>
const T& max(const T& a, const T& b) {
    return a<b?b:a;
}

// call order defines the return type
// cannot use reference here, as second to return type creates a temporary object
template<typename T, typename U>
const U& max(const T& a, const U& b) {
    return a<b?b:a;
}

// R does not depend on call params
// mention explicitly the argument list
// max<double,int,int>
// max<double>(8,10)
template<typename R, typename T, typename U>
R max(const T& a, const U& b) {
    return a<b?b:a;
}


int main() {

}




