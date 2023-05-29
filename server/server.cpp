#ifndef SERVER_H
#define SERVER_H
#include <boost/asio.hpp>
#include "acceptor.hpp"
#include "../service/container.hpp"


class Server {
public:
    Server() : m_stop(false) {}

    void Start(unsigned short port_num) {
        m_thread.reset(new std::thread([this, port_num]() {
            Run(port_num);
        }));
    }

    void Stop() {
        m_stop.store(true);
        m_thread->join();
    }

private:
    void Run(unsigned short port_num) {
        Acceptor acc(m_ios, port_num);

        while (!m_stop.load()) {
            acc.Accept();
        }
    }

private:
    std::unique_ptr<std::thread> m_thread;
    std::atomic<bool> m_stop;
    boost::asio::io_service m_ios;
    //service::Container m_container;
};


#endif