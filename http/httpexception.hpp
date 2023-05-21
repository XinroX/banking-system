#include <exception>

class HTTPException : public std::exception {
public:
    HTTPException(char* msg) : message{msg} {}    

    const char* what(){
        return message;
    }  
private:
    const char* message;
    
};