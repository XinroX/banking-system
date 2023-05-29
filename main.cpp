#include "server/server.cpp"

int main() {
    try {
        Server srv;
        srv.Start(3333);
    }
    catch (boost::system::system_error& e) {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << '\n';
    }
}