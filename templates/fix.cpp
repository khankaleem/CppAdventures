#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
using namespace std;





// tag to type mapping
template<int x>
struct FixType;

constexpr unsigned int FIX_OrderType_Tag = 30;
constexpr const char FIX_OrderType_Tag_Text[] = "18";
template<>
struct FixType<FIX_OrderType_Tag>
{
  public:
    typedef char type;
};

constexpr unsigned int Fix_Symbol_Tag = 55;
constexprconst char Fix_Symbol_Tag_Text[] = "55";
template<>
struct FixType<Fix_Symbol_Tag>
{
  public:
    typedef std::string type;
};
#define Fix_Symbol_Type             char*


template <unsigned int tag>
void printType() {
    if (is_same<typename FixType<tag>::type, char>::value) {
        cout << "CHAR\n";
    }
    else if (is_same<typename FixType<tag>::type, int>::value) {
        cout << "INT\n";
    }
    else {
        cout << "NOT\n";
    }
}



int main() {

    printType<FIX_OrderType_Tag>();

}