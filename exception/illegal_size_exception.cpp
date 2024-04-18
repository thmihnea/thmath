#include "illegal_size_exception.h"

#include <stdexcept>
#include <string>

IllegalSizeException::IllegalSizeException(const std::string& message)
{
    this->message = message;
}

const char* IllegalSizeException::what() const noexcept
{
    return this->message.c_str();
}