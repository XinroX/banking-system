#ifndef ISERVICE_H
#define ISERVICE_H
#include <memory>
#include <boost/asio.hpp>

namespace service {

class IService {
public:
    virtual void ConfigureService(std::shared_ptr<boost::asio::ip::tcp::socket> sock) = 0;
    virtual void StartHandling() = 0;
    virtual ~IService(){}
};


} // namespace service



#endif