#include "vector.h"
#include "exception/illegal_access_exception.h"
#include "exception/different_size_exception.h"
#include <stdexcept>
#include <iostream>
#include <string>

thmath::Vector::Vector(int size, double* entries)
{
    this->size = size;
    this->entries = entries;
}

thmath::Vector::~Vector()
{
    
}

double thmath::Vector::get_component(const int index)
{
    if (index >= this->size) 
    {
        throw IllegalAccessException("Attempted an illegal vector access of a component that does not exist.");
        return NULL;
    }
    return this->entries[index];
}

int thmath::Vector::get_size()
{
    return this->size;
}

thmath::Vector thmath::Vector::operator+(const Vector& vec)
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException("Attempted to add vectors of different sizes.");
    }
    double* final_entries = new double[this->size];
    for (int index = 0; index < this->size; index++)
    {
        final_entries[index] = this->entries[index] + vec.entries[index];
    }
    return Vector(this->size, final_entries);
}

thmath::Vector thmath::Vector::operator-(const Vector& vec)
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException("Attempted to subtract vectors of different sizes.");
    }
    double* final_entries = new double[this->size];
    for (int index = 0; index < this->size; index++)
    {
        final_entries[index] = this->entries[index] - vec.entries[index];
    }
    return Vector(this->size, final_entries);
}

std::string thmath::Vector::to_string()
{
    std::string s = "Vector{size=" + std::to_string(this->size) + ", elements=[";
    for (int index = 0; index < this->size - 1; index++)
    {
        s += std::to_string(this->entries[index]) + ",";
    }
    s += std::to_string(this->entries[this->size - 1]) + "]}";
    return s;
}