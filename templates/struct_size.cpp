#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <set>
#include <stddef.h>     /* offsetof */
using namespace std;

// #pragma pack(1)

#pragma pack (push)
#pragma pack (1)
struct Response
{
   uint64_t m_orderId = 0; // 0
   uint8_t m_internalAccount = 0; //8
   char m_recoveryTag[10] = ""; // 9
   uint16_t m_exchange; // 2
   char __padding2[3]; // 3
};


struct Response2
{
   uint64_t m_orderId = 0; // 0
   uint8_t m_internalAccount = 0; //8
   char m_recoveryTag[10] = ""; // 9
   uint16_t m_exchange; // 2
   char __padding2[3]; // 3
};
#pragma pack (pop)
int main() {
    std::cout << sizeof(Response) << '\n';

    std::cout << (int)offsetof(struct Response, m_orderId) << '\n';
    std::cout << (int)offsetof(struct Response, m_internalAccount) << '\n';
    std::cout << (int)offsetof(struct Response, m_recoveryTag) << '\n';
    std::cout << (int)offsetof(struct Response, m_exchange) << '\n';
    std::cout << (int)offsetof(struct Response, __padding2) << '\n';

    std::cout << sizeof(Response2) << '\n';

    std::cout << (int)offsetof(struct Response2, m_orderId) << '\n';
    std::cout << (int)offsetof(struct Response2, m_internalAccount) << '\n';
    std::cout << (int)offsetof(struct Response2, m_recoveryTag) << '\n';
    std::cout << (int)offsetof(struct Response2, m_exchange) << '\n';
    std::cout << (int)offsetof(struct Response2, __padding2) << '\n';
}

