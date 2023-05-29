#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include <boost/asio.hpp>
#include <iostream>
#include "../service/container.hpp"
#include "../http/httpheader.hpp"
#include "../di.hpp"
#include "../http/httprequest.hpp"

class Acceptor {
public:
    Acceptor(boost::asio::io_service& ios, unsigned short port_num):
    m_ios(ios),
    m_acceptor(m_ios, boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("192.168.56.1"), port_num))
    {
        m_acceptor.listen();
    }

    void Accept() {
        std::shared_ptr<boost::asio::ip::tcp::socket> sock(new boost::asio::ip::tcp::socket(m_ios));
        m_acceptor.accept(*sock.get());

        // std::unique_ptr<service::IService> service = m_container.CreateHTTPService();
        // service->ConfigureService(sock);
    }

private:
    boost::asio::io_service& m_ios;
    boost::asio::ip::tcp::acceptor m_acceptor;
};

#endif