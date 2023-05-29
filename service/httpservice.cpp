#include "httpservice.hpp"
#include <fstream>
#include <boost/filesystem.hpp>

namespace service {

void HTTPService::ConfigureService(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
    m_sock = sock;
}

void HTTPService::StartHandling() {
    // boost::asio::async_read_until(*m_sock.get(), m_request_buf, "\r\n\r\n",
    // [this](const boost::system::error_code& ec, std::size_t bytes_transferred) {
    //     on_header_received(ec, bytes_transferred);
    // });
}

void HTTPService::on_header_received(const boost::system::error_code& ec, std::size_t bytes_transferred) {
    if (ec) {
        std::cout << "Error occured! Error code = " << ec.value() << ". Message: " << ec.message() << '\n';
        return;
    }


    std::istream input_buf(&m_request_buf);
    std::string request;
    while (!input_buf.eof()) {
        input_buf >> request;
        request += ' ';
    }
    request += "\r\n\r\n";
    m_header->ConfigureHeader(request);

    boost::asio::async_read_until(*m_sock.get(), m_request_buf, "\r\n",
    [this](const boost::system::error_code& ec, std::size_t bytes_transferred) {
        std::istream input_buf(&m_request_buf);
        input_buf >> m_body;
        process_header();
    });

}

void HTTPService::process_header() {
    if (m_header->GetMethod() == http::HTTPMethod::GET && m_header->GetUri() == "/authorize") {
        authorize();
    }
    else if (m_header->GetMethod() == http::HTTPMethod::GET && m_header->GetUri() == "/balance") {

    }
}


void HTTPService::authorize() {
    std::string path = "./keys/" + m_body;
    if (boost::filesystem::exists(path)) {
        std::ifstream file(path);
        std::string token;
        file >> token;
        m_response->ConfigureResponse(200, token);
    }
    else {
        m_response->ConfigureResponse(404, "");
    }
}


void HTTPService::send_response() {
    const std::string message = m_response->GenerateResponse();
    boost::asio::async_write(*m_sock.get(), boost::asio::buffer(message),
    [this](const boost::system::error_code& ec, std::size_t bytes_transferred) {
        if (ec) {
            std::cout << "Error occured! Error code = " << ec.value() << ". Message: " << ec.message() << '\n';
        }
    });
}


} // service