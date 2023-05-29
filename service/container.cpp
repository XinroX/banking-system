#include "container.hpp"
#include "../http/httpheader.hpp"
#include "../http/httprequest.hpp"
#include "../http/httpresponse.hpp"



namespace service {
    std::unique_ptr<IService> Container::CreateHTTPService() {
        auto injector = DI::make_injector(
            DI::bind<http::IHTTPHeader>().to<http::HTTPHeader>(),
            DI::bind<http::IHTTPRequest>().to<http::HTTPRequest>(),
            DI::bind<http::IHTTPResponse>().to<http::HTTPResponse>()
            //DI::bind<IService>().to<HTTPService>()
        );
        return std::make_unique<HTTPService>(injector.create<HTTPService>());
    }
}