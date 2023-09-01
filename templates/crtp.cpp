#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
using namespace std;

template<typename DerivedT>
class Base {
    public:
        Base()=default;
        void print() {
            cout << "Base\n";
        }

        DerivedT* getDerived() {
            return static_cast<DerivedT*>(this);
        }

        void process() {
            getDerived()->print();
        }

};

class Derived: public Base<Derived> {
    public:
        Derived()=default;
        using Base = Base<Derived>;

        int print() {
            std::cout << "Derived\n";
            Base::print();
        }
};

int main() {
    Derived d;
    d.process();
}