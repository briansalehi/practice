#include <practice/practice.hpp>
#include <iostream>

int main()
{
    pr::server server{};
    std::cout << server.address() << ":" << server.port();
}
