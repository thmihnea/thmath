#pragma once

#ifndef __THMATH_ILLEGAL_ACCESS_EXCEPTION_
#define __THMATH_ILLEGAL_ACCESS_EXCEPTION_

#include <stdexcept>
#include <string>

class IllegalAccessException : public std::exception
{
private:
    std::string message;
public:
    IllegalAccessException(const std::string& message);

    const char* what() const noexcept;
};

#endif