#include "illegal_access_exception.h"

#include <stdexcept>
#include <string>

IllegalAccessException::IllegalAccessException(const std::string& message)
{
    this->message = message;
}

const char* IllegalAccessException::what() const noexcept
{
    return this->message.c_str();
}