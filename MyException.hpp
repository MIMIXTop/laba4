#include <iostream>
#include <string>
#include <exception>

namespace std {
    class emptyVector : public std::exception
    {
    private:
        std::string message;
    public:
        emptyVector(const std::string& message_) : message(message_){}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };

    class my_out_of_range : public std::out_of_range
    {
    private:
        std::string message;
    public:
        my_out_of_range(const std::string& message_) : message(message_), std::out_of_range(message_){}
        const char* what() const noexcept override {
            return message.c_str();
        }
    };
}