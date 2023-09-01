#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <set>
#include <stddef.h>

template<typename T, size_t MAXSIZE>
class Stack {
private:
 T elems[MAXSIZE];
 size_t numelems;

public:
 Stack();
 void push(const T&);
 void pop();
 T top() const;
 bool empty() const {
    return numelems==0;
 }
 bool full() const {
    return numelems==MAXSIZE;
 }
 void print() const {
    for (size_t i = 0; i < numelems; i++) {
        std::cout << elems[i] << ' ';
    }
    std::cout << '\n';
 }
};

template<typename T, size_t MAXSIZE>
Stack<T, MAXSIZE>::Stack() {
    numelems=0;
}


template<typename T, size_t MAXSIZE>
void Stack<T, MAXSIZE>::push(const T& elem) {
    if (this->full()) {
        exit(1);
    }
    elems[numelems] = elem;
    numelems++;
}

template<typename T, size_t MAXSIZE>
void Stack<T, MAXSIZE>::pop() {
    if (this->empty()) {
        exit(1);
    }
    numelems--;
}

template<typename T, size_t MAXSIZE>
T Stack<T, MAXSIZE>::top() const {
    if (this->empty()) {
        exit(1);
    }
    return elems[numelems-1];
}

int main() {
    ::Stack<int, 100> st;
    st.push(100);
    st.push(200);
    st.pop();
    st.print();
}