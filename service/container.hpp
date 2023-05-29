#ifndef CONTAINER_H
#define CONTAINER_H
#include "httpservice.hpp"
#include "../di.hpp"

namespace service {
namespace DI = boost::di;
class Container {
public:
    std::unique_ptr<IService> CreateHTTPService();
    //std::unique_ptr<IService>
};

} // service


#endif