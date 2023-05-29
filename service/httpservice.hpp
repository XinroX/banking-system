#ifndef HTTPSERVICE_H
#define HTTPSERVICE_H
#include "iservice.hpp"
#include "../http/ihttprequest.hpp"
#include "../http/ihttpheader.hpp"
#include "../http/httpmethod.hpp"
#include "../http/httpresponse.hpp"
#include <iostream>
#include <boost/filesystem.hpp>


namespace service {

class HTTPService : public IService {
public:
    HTTPService(HTTPService&&) {}
    HTTPService(std::unique_ptr<http::IHTTPRequest> request, std::unique_ptr<http::IHTTPResponse> response, std::unique_ptr<http::IHTTPHeader> header) : 
    m_request(std::move(request)), m_response(std::move(response)), m_header(std::move(header)) {}
    void ConfigureService(std::shared_ptr<boost::asio::ip::tcp::socket> sock) override;
    void StartHandling() override;

private:

    void on_header_received(const boost::system::error_code& ec, std::size_t bytes_transferred);
    virtual void process_header();

    void authorize();

    void read_body();

    void send_response();

    std::shared_ptr<boost::asio::ip::tcp::socket> m_sock;
    std::unique_ptr<http::IHTTPRequest> m_request;
    std::unique_ptr<http::IHTTPHeader> m_header;
    boost::asio::streambuf m_request_buf;
    std::unique_ptr<http::IHTTPResponse> m_response;
    std::string m_body;
};

} // service



#endif