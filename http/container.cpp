#include "container.hpp"

namespace http {
    std::unique_ptr<IHTTPRequest> Container::CreateRequest() {
        auto injector = DI::make_injector(
            DI::bind<IHTTPHeader>().to<HTTPHeader>(),
            DI::bind<IHTTPRequest>().to<HTTPRequest>()
        );

        //return std::make_unique<IHTTPRequest>(injector.create<HTTPRequest>());
    }
}