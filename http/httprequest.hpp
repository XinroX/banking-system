#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <memory>
#include "ihttpheader.hpp"
#include "ihttprequest.hpp"

namespace http {
class HTTPRequest : public IHTTPRequest {
    friend class Container;
private:
    HTTPRequest(std::unique_ptr<IHTTPHeader> header) : m_header(std::move(header))
    {}
public:

    void ConfigureRequest(const std::string& m_request_buf) override;
private:
    std::unique_ptr<IHTTPHeader> m_header;
};

} // namespace http


#endif