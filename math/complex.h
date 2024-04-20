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

#pragma once

#ifndef __THMATH_COMPLEX_
#define __THMATH_COMPLEX_

#include <algorithm>
#include <string>

namespace thmath
{
    class Complex
    {
    private:
        double real;
        double imaginary;

    public:
        /**
         * Default constructor for the Complex class.
         * 
         * @param real The real part of the complex number.
         * @param imaginary The imaginary part of the complex number.
         * @return A new complex number object.
        */
        Complex(double real, double imaginary);
        
        /**
         * Initializer list constructor for the Complex class.
         * This allows the object to be constructed by initializing
         * the real and imaginary parts directly from an initializer list.
         * 
         * @param args The initializer list containing the real and imaginary parts.
         * @return A new complex number object.
        */
        Complex(std::initializer_list<double> args);

        /**
         * Copy constructor for the complex class.
         * 
         * @param other The complex number which will be
         * copied into this one.
         * @return A new complex number object.
        */
        Complex(const Complex& other);

        /**
         * Destructor for the Complex class.
        */
        ~Complex();

        /**
         * Get the real part of the complex number.
         * 
         * @return The real part of the complex number.
        */
        double get_real() const;

        /**
         * Get the imaginary part of the complex number.
         * 
         * @return The imaginary part of the complex number.
        */
        double get_imaginary() const;

        /**
         * Calculate the norm (magnitude) of the complex number.
         * 
         * @return The norm of the complex number.
        */
        double norm() const;

        /**
         * Calculate the argument (angle) of the complex number.
         * 
         * @return The argument of the complex number.
        */
        double argument() const;

        /**
         * Calculate the conjugate of the complex number.
         * 
         * @return The conjugate of the complex number.
        */
        Complex conjugate() const;

        /**
         * Overloaded equality operator for comparing two complex numbers.
         * 
         * @param complex The complex number to compare with.
         * @return True if the complex numbers are equal, false otherwise.
        */
        bool operator==(const Complex& complex) const;

        /**
         * Overloaded assignment operator for complex numbers.
         * 
         * @param other The complex numbers which shall be
         * assigned to this one.
         * @return A new complex number object.
        */
        Complex& operator=(const Complex& other);

        /**
         * Overloaded addition operator for adding two complex numbers.
         * 
         * @param complex The complex number to add.
         * @return The result of the addition operation.
        */
        Complex operator+(const Complex& complex) const;

        /**
         * Overloaded compound addition operator for adding two complex numbers.
         * 
         * @param complex The complex number to add.
         * @return The result of the addition operation.
        */
        Complex& operator+=(const Complex& complex);

        /**
         * Overloaded subtraction operator for subtracting two complex numbers.
         * 
         * @param complex The complex number to subtract.
         * @return The result of the subtraction operation.
        */
        Complex operator-(const Complex& complex) const;

        /**
         * Overloaded compound subtraction operator for subtracting two complex numbers.
         * 
         * @param complex The complex number to subtract.
         * @return The result of the subtraction operation.
        */
        Complex& operator-=(const Complex& complex);

        /**
         * Overloaded multiplication operator for multiplying two complex numbers.
         * 
         * @param complex The complex number to multiply.
         * @return The result of the multiplication operation.
        */
        Complex operator*(const Complex& complex) const;

        /**
         * Overloaded compound multiplication operator for multiplying two complex numbers.
         * 
         * @param complex The complex number to multiply.
         * @return The result of the multiplication operation.
        */
        Complex& operator*=(const Complex& complex);

        /**
         * Raises a complex number to another complex number.
         * 
         * @param complex The number which is used as the exponent
         * to our current base.
         * @return The result of the exponentiation.
        */
        Complex operator^(const Complex& complex) const;
        
        /**
         * Stringify the complex number object for it to be
         * easily printed to console or for any other particular
         * uses.
         * 
         * @return The stringified version of the complex number.
        */
        std::string to_string() const;
    };
}

#endif
