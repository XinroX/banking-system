#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include <map>
#include "ihttpresponse.hpp"
namespace http {
class HTTPResponse : public IHTTPResponse {
public:
    void ConfigureResponse(const int status_code, const std::string& body) override;

    std::string GenerateResponse() const override;


    static const std::map<unsigned int, std::string> http_status_table;

private:
    std::string m_status_code;
    std::string m_body;
};


} // namespace http


#endif