#pragma once

#ifndef __THMATH_VECTOR_
#define __THMATH_VECTOR_

#include <string>

namespace thmath
{
    class Vector
    {
    private:
        double* entries;
        int size;

    public:
        Vector(const int size, double* entries);

        ~Vector();

        double get_component(const int index);

        int get_size();

        Vector operator+(const Vector& vec);

        Vector operator-(const Vector& vec);

        std::string to_string();
    };
}


#endif