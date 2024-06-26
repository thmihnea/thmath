/*
 * This file is part of thmath.
 *
 * Developed for the the thmath Mathematics Library.
 * This product includes software developed by Mihnea Morarescu and
 * all affiliated contributors of thmath.
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "vector.h"
#include "../exception/illegal_access_exception.h"
#include "../exception/different_size_exception.h"
#include "../exception/illegal_size_exception.h"
#include "../exception/messages.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

thmath::Vector::Vector(size_t size, double* entries)
{
    if (size <= 0)
    {
        throw IllegalSizeException(ILLEGAL_SIZE_MESSAGE);
    }
    this->size = size;
    this->entries = new double[size];

    std::copy(entries, entries + size, this->entries);
}

thmath::Vector::Vector(const Vector& other) : size(other.size), entries(new double[other.size])
{
    std::copy(other.entries, other.entries + other.size, this->entries);
}

thmath::Vector::Vector(std::initializer_list<double> entries)
{
    if (entries.size() <= 0)
    {
        throw IllegalSizeException(ILLEGAL_SIZE_MESSAGE);
    }
    this->size = entries.size();
    this->entries = new double[this->size];

    std::copy(entries.begin(), entries.end(), this->entries);
}

thmath::Vector::~Vector()
{
    delete[] this->entries;
}

double thmath::Vector::get_component(const int index) const
{
    if (index >= this->size) 
    {
        throw IllegalAccessException(ILLEGAL_ACCESS_MESSAGE);
    }
    return this->entries[index];
}

double* thmath::Vector::get_entries() const
{
    return this->entries;
}

size_t thmath::Vector::get_size() const
{
    return this->size;
}

double thmath::Vector::norm(double p) const
{
    double max_abs = *std::max_element(this->entries, this->entries + this->size, [](double a, double b) {
        return std::abs(a) < std::abs(b);
    });

    std::vector<double> scaled_entries(this->size);
    std::transform(this->entries, this->entries + this->size, scaled_entries.begin(), [max_abs](double x) {
        return x / max_abs;
    });

    return max_abs * std::pow(
        std::accumulate(scaled_entries.begin(), scaled_entries.end(), 0.0, [p](double total, double x) {
            return total + std::pow(std::abs(x), p);
        }),
        1.0 / p
    );
}

double thmath::Vector::norm() const
{
    return norm(2);
}

double thmath::Vector::infinity_norm() const
{
    return *std::max_element(this->entries, this->entries + this->size);
}

double thmath::Vector::dot_product(const Vector& vec) const
{
    if (this->size != vec.size) 
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }
    return std::inner_product(
        this->entries, this->entries + this->size, vec.entries, 0.0
    );
}

thmath::Vector thmath::Vector::vector_product(const Vector& vec) const
{
    if (this->size != vec.size || this->size > 3 || this->size < 2)
    {
        throw IllegalSizeException(ILLEGAL_SIZE_MESSAGE);
    }
    if (this->size == 2)
    {
        double z = get_component(0) * vec.get_component(1) - get_component(1) * vec.get_component(0);
        return Vector{0, 0, z};
    }
    else 
    {
        double x = get_component(1) * vec.get_component(2) - get_component(2) * vec.get_component(1);
        double y = -(get_component(0) * vec.get_component(2) - get_component(2) * vec.get_component(0));
        double z = get_component(0) * vec.get_component(1) - get_component(1) * vec.get_component(0);
        return Vector{x, y, z};
    }
}

thmath::Vector& thmath::Vector::scale(double lambda)
{
    std::transform(
        this->entries, this->entries + this->size, this->entries, [lambda](double element){
            return element * lambda;
        }
    );
    return *this;
}

thmath::Vector& thmath::Vector::normalized(double p)
{
    double p_norm = norm(p);
    std::transform(
        this->entries, this->entries + this->size, this->entries, [p_norm](double element){
            return element / p_norm;
        }
    );
    return *this;
}

thmath::Vector& thmath::Vector::normalized()
{
    return normalized(2);
}

double thmath::Vector::angle(const Vector& vec, bool cosine) const
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }
    double cos = dot_product(vec) / (norm() * vec.norm());
    return cosine ? cos : std::acos(cos);
}

bool thmath::Vector::is_parallel(const Vector& vec) const
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }

    return std::abs(dot_product(vec)) == norm() * vec.norm();
}

bool thmath::Vector::is_perpendicular(const Vector& vec) const
{
    return dot_product(vec) == 0;
}

bool thmath::Vector::operator==(const Vector& vec) const
{
    if (this->size != vec.size)
    {
        return false;
    }
    for (size_t index = 0; index < this->size; index++)
    {
        if (get_component(index) != vec.get_component(index))
        {
            return false;
        }
    }
    return true;
}

thmath::Vector& thmath::Vector::operator=(const Vector& vec)
{
    if (this != &vec)
    {
        delete[] this->entries;
        this->size = vec.size;
        this->entries = new double[vec.size];
        std::copy(vec.entries, vec.entries + vec.size, this->entries);
    }
    return *this;
}

thmath::Vector thmath::Vector::operator+(const Vector& vec) const
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }
    double* final_entries = new double[this->size];
    for (int index = 0; index < this->size; index++)
    {
        final_entries[index] = this->entries[index] + vec.entries[index];
    }
    return Vector(this->size, final_entries);
}

thmath::Vector& thmath::Vector::operator+=(const Vector& vec)
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }
    std::transform(
            this->entries, this->entries + this->size, vec.entries, this->entries, [](double a, double b){
            return a + b;
        }
    );
    return *this;
}

thmath::Vector thmath::Vector::operator-(const Vector& vec) const
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }
    double* final_entries = new double[this->size];
    for (int index = 0; index < this->size; index++)
    {
        final_entries[index] = this->entries[index] - vec.entries[index];
    }
    return Vector(this->size, final_entries);
}

thmath::Vector& thmath::Vector::operator-=(const Vector& vec)
{
    if (this->size != vec.size)
    {
        throw DifferentSizeException(DIFFERENT_SIZE_MESSAGE);
    }
    std::transform(
            this->entries, this->entries + this->size, vec.entries, this->entries, [](double a, double b){
            return a - b;
        }
    );
    return *this;
}

thmath::Vector thmath::Vector::operator*(double lambda) const
{
    double* scaled = new double[this->size];
    std::transform(
        this->entries, this->entries + this->size, scaled, [lambda](double d){
            return lambda * d;
        }
    );
    return Vector(this->size, scaled);
}

thmath::Vector& thmath::Vector::operator*=(double lambda)
{
    std::transform(
        this->entries, this->entries + this->size, this->entries, [lambda](double d){
            return lambda * d;
        }
    );
    return *this;
}

std::string thmath::Vector::to_string() const
{ 
    std::string s = "Vector={size=" + std::to_string(this->size) + ", elements=[";
    for (int index = 0; index < this->size - 1; index++)
    {
        s += std::to_string(this->entries[index]) + ", ";
    }
    s += std::to_string(this->entries[this->size - 1]) + "]}";
    return s;
}