#ifndef CONTAINER_H
#define CONTAINER_H

#include "di.hpp"
#include "httpheader.hpp"
#include "httprequest.hpp"
namespace http {
namespace DI = boost::di;
class Container {
public:
    std::unique_ptr<IHTTPRequest> CreateRequest();

};

} // namespace http

#endif