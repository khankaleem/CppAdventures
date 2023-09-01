#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
using namespace std;

template<typename...>
int add();

template<>
int add() {
    return 0;
}

template<typename T, typename... ArgTypes>
int add(T t, ArgTypes... args) {
    return t + add(args...);
}

int main() {
    cout << add(100, 200, 300, 400) << '\n';
}
