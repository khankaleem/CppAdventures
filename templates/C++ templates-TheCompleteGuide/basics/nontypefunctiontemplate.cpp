#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <set>
#include <stddef.h>

template<typename T, int64_t VALUE = 0>//int or pointer to objects with external linkage
T addValue(const T& x) {
    return x+VALUE;
}

void transform(std::vector<int64_t>& v, std::function<int64_t(int64_t)> func) {
    for (size_t i = 0;i < v.size(); i++) {
        v[i] = func(v[i]);
    }
}

int main() {
    std::cout << addValue<int64_t, 1>(10) << '\n';
    std::vector<int64_t> v={1,2,3};
    transform(v,addValue<int64_t,1>);
    for (size_t i = 0;i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}