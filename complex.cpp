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

#include "complex.h"
#include "exception/illegal_size_exception.h"
#include "exception/messages.h"
#include <cmath>
#include <algorithm>
#include <sstream>

thmath::Complex::Complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

thmath::Complex::Complex(std::initializer_list<double> args)
{
    if (args.size() != 2)
    {
        throw IllegalSizeException(ILLEGAL_SIZE_MESSAGE);
    }
    auto it = args.begin();
    this->real = *it;
    this->imaginary = *(++it);
}

thmath::Complex::~Complex()
{
    
}

double thmath::Complex::get_real() const
{
    return this->real;
}

double thmath::Complex::get_imaginary() const
{
    return this->imaginary;
}

double thmath::Complex::norm() const
{
    return std::sqrt(
        this->real * this->real + this->imaginary * this->imaginary
    );
}

double thmath::Complex::argument() const
{
    return std::atan(this->imaginary / this->real);
}

thmath::Complex thmath::Complex::conjugate() const
{
    return thmath::Complex(
        this->real,
        -this->imaginary
    );
}

bool thmath::Complex::operator==(const Complex& complex) const 
{
    return (this->real == complex.real) && (this->imaginary == complex.imaginary);
}

thmath::Complex thmath::Complex::operator+(const Complex& complex) const 
{
    return Complex(this->real + complex.real, this->imaginary + complex.imaginary);
}


thmath::Complex& thmath::Complex::operator+=(const Complex& complex) 
{
    this->real += complex.real;
    this->imaginary += complex.imaginary;
    return *this;
}

thmath::Complex thmath::Complex::operator-(const Complex& complex) const 
{
    return Complex(this->real - complex.real, this->imaginary - complex.imaginary);
}

thmath::Complex& thmath::Complex::operator-=(const Complex& complex)
{
    this->real -= complex.real;
    this->imaginary -= complex.imaginary;
    return *this;
}

thmath::Complex thmath::Complex::operator*(const Complex& complex) const 
{
    double result_real = this->real * complex.real - this->imaginary * complex.imaginary;
    double result_imaginary = this->real * complex.imaginary + this->imaginary * complex.real;
    return Complex(result_real, result_imaginary);
}

thmath::Complex& thmath::Complex::operator*=(const Complex& complex) 
{
    double result_real = this->real * complex.real - this->imaginary * complex.imaginary;
    double result_imaginary = this->real * complex.imaginary + this->imaginary * complex.real;
    real = result_real;
    imaginary = result_imaginary;
    return *this;
}

thmath::Complex thmath::Complex::operator^(const Complex& complex) const 
{
    double a = complex.real;
    double b = complex.imaginary;
    double arg = argument();
    double log = std::log(norm());

    double new_norm = std::exp(a*log - b*arg);
    double theta = a*arg + b*log;

    return {new_norm * std::cos(theta), new_norm * std::sin(theta)};
}


std::string thmath::Complex::to_string() const
{
    std::ostringstream stream;
    stream << "Complex={real=" << this->real << ", imaginary=" << this->imaginary << "}";
    return stream.str();
}

