#include "different_size_exception.h"

#include <stdexcept>
#include <string>

DifferentSizeException::DifferentSizeException(const std::string& message)
{
    this->message = message;
}

const char* DifferentSizeException::what() const noexcept
{
    return this->message.c_str();
}