#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <string>

namespace pr
{
class server
{
public:
    server();

    std::string address() const noexcept;
    std::uint8_t port() const noexcept;

private:
    boost::asio::ip::address_v6 m_address;
    boost::asio::ip::port_type m_port;
};
} // pr
