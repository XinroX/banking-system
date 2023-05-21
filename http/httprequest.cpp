#include <iostream>
#include <sstream>

#include "httprequest.hpp"
#include "httpexception.hpp"
namespace http {
void HTTPRequest::ConfigureRequest(const std::string& m_request_buf) {
    std::size_t header_separator_pos = m_request_buf.find("\r\n\r\n");
    if (header_separator_pos == std::string::npos) {
        throw HTTPException("HTTPException: Invalid header format");
        return;
    }

    m_header->ConfigureHeader(m_request_buf.substr(0, header_separator_pos));

    std::istringstream body_content_buf(m_request_buf.substr(header_separator_pos));
    std::string body_content;
    body_content_buf >> body_content;

    if (body_content == "") {
        throw HTTPException("HTTPException: Body content empty");
        return;
    }

}

} // namespace http