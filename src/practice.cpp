#include <practice/practice.hpp>

using namespace pr;

server::server()
    : m_address{boost::asio::ip::address_v6::any()}
    , m_port{9000}
{
}

std::string server::address() const noexcept
{
    return m_address.to_string();
}

std::uint8_t server::port() const noexcept
{
    return m_port;
}
