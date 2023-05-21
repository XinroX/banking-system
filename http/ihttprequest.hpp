#ifndef IHTTPREQUEST_H
#define IHTTPREQUEST_H
#include <string>
namespace http {
class IHTTPRequest {
public:
    virtual void ConfigureRequest(const std::string&) = 0;
};

} // namespace http

#endif