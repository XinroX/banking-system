#include "httpresponse.hpp"


namespace http {

void HTTPResponse::ConfigureResponse(const int status_code, const std::string& body) {
    m_status_code = http_status_table.at(status_code);
    m_body = body;
}

std::string HTTPResponse::GenerateResponse() const {
    std::string buf = "HTTP/1.1 " + m_status_code + "\r\n\r\n";
    if (m_body == "") {
        return buf;
    }
    buf += m_body + "\r\n";
    return buf;
}


const std::map<unsigned int, std::string> HTTPResponse::http_status_table =
{
  { 200, "200 OK" },
  { 404, "404 Not Found" },
  { 413, "413 Request Entity Too Large" },
  { 500, "500 Server Error" },
  { 501, "501 Not Implemented" },
  { 505, "505 HTTP Version Not Supported" }
};

} // namespace http