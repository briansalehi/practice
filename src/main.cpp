#include <practice/practice.hpp>
#include <print>

int main()
{
    pr::server server{};
    std::println("{}:{}", server.address(), server.port());
}
