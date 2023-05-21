#ifndef IHTTPRESPONSE_H
#define IHTTPRESPONSE_H

#include <string>

namespace http {

class IHTTPResponse {
public:
    virtual void ConfigureResponse(const int status_code, const std::string& body) = 0;
    virtual std::string GenerateResponse() const = 0;
};

} // namespace http


#endif