#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
using namespace std;

template<typename...>
struct list;

template<>
struct list<> {
    list(){}
};

template<typename T> 
struct list<T> {
    T head;
    list(){}
    list(const T& h) : head(h) {}
};

template<typename T, typename... Args> 
struct list<T, Args...> {
    T head;
    list(){}
    list(const T& h, const list<Args...>& t) : head(h) {}
};

list<> getlist() {
    return list<>();
}

template<typename T>
list<T> getlist(const T& t) {
    return list<T>(t);
}

template<typename T, typename... Args>
list<T, Args...> getlist(const T& t, const Args&... args) {
    return list<T, Args... >( t, getlist(args...) );
}

int main() {
    getlist(100, 'a', 1.59);
}