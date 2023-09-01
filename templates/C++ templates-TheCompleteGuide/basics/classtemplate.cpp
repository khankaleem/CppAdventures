#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <set>
#include <stddef.h>

template <typename T>
class stack {
private:
    std::vector<T> stk;
public:
    void push(const T&);
    void pop();
    T top() const;//not allowed to change member, read only
    bool empty() const {//not allowed to change member, read only
        return stk.empty();
    }
    void multiply() {//function is not instantiated
        std::cout << this->top() * 100;
    }
};

template<typename T>
void stack<T>::push(const T& t) {
    stk.push_back(t);
}

template<typename T>
void stack<T>::pop() {
    if (not this->empty()) {
        stk.pop_back();
        return;
    }
    throw std::out_of_range("Stack is empty!");
}

template<typename T>
T stack<T>::top() const {
    if (not this->empty()) {
        return stk.back();
    }
    throw std::out_of_range("Stack is empty!");
}


template <>//specializing template class
class stack<std::string> {
private:
    std::vector<std::string> stk;
public:
    void push(const std::string&);
    void pop();
    std::string top() const;//not allowed to change member, read only
    bool empty() const {//not allowed to change member, read only
        return stk.empty();
    }
};
void stack<std::string>::push(const std::string& t) {
}
void stack<std::string>::pop() {
}
std::string stack<std::string>::top() const {
    return "";
}

int main() {
    ::stack<int> s;
    s.push(100);
    s.pop();
    s.push(20);
    std::cout << s.top() << '\n';
    s.pop();

    ::stack<std::string> m;
    m.push("kaleem");
    m.pop();
    m.pop();
}
