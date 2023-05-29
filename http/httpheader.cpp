
#include "httpheader.hpp"

namespace http {

HTTPMethod getMethodByStatusLine(const std::string& status_line) {
    if (status_line.find("GET") != std::string::npos) return HTTPMethod::GET;
    else if (status_line.find("PATCH")) return HTTPMethod::PATCH;
    else throw HTTPException("HTTPException: Invalid verb");
}

std::string getUriByStatusLine(const std::string& status_line) {
    std::size_t first_space = status_line.find(' ');
    if (first_space == std::string::npos) {
        throw HTTPException("HTTPException: Invalid status line format");
    }

    std::size_t second_space = status_line.find_first_of(' ', first_space);
    if (second_space == std::string::npos) {
        throw HTTPException("HTTPException: Invalid status line format");
    }

    std::string uri = status_line.substr(first_space, second_space - first_space);
    return uri;
}
void HTTPHeader::ConfigureHeader(const std::string& header_buf) {
    std::size_t status_line_separator = header_buf.find("\r\n");
    if (status_line_separator == std::string::npos) {
        throw HTTPException("HTTPException: Invalid status line");
        return;
    }

    std::string status_line = header_buf.substr(0, status_line_separator);
    m_method = getMethodByStatusLine(status_line);
    m_uri = getUriByStatusLine(status_line);

    
}

HTTPMethod HTTPHeader::GetMethod() const{
    return m_method;
}
const std::string& HTTPHeader::GetUri() const {
    return m_uri;
}

} // namespace http;