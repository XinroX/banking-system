#ifndef IHTTPHEADER_H
#define IHTTPHEADER_H

#include <string>
#include "httpmethod.hpp"

namespace http {

class IHTTPHeader {
public:
    virtual void ConfigureHeader(const std::string&) = 0;
    virtual HTTPMethod GetMethod() const = 0;
    virtual const std::string& GetUri() const = 0;
    virtual ~IHTTPHeader(){}
};

} // namespace http

#endif