#ifndef HTTPHEADER_H
#define HTTPHEADER_H
#include "ihttpheader.hpp"
#include "httpexception.hpp"

namespace http {
class HTTPHeader : public IHTTPHeader {
public:
    void ConfigureHeader(const std::string& header_buf) override;
    HTTPMethod GetMethod() const override;
    const std::string& GetUri() const override;
private:
    HTTPMethod m_method;
    std::string m_uri;
};


} // namespace http

#endif