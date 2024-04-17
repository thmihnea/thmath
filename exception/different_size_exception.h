#pragma once

#ifndef __THMATH_DIFFERENT_SIZE_EXCEPTION_
#define __THMATH_DIFFERENT_SIZE_EXCEPTION_

#include <stdexcept>
#include <string>

class DifferentSizeException : public std::exception
{
private:
    std::string message;
public:
    DifferentSizeException(const std::string& message);

    const char* what() const noexcept;
};

#endif