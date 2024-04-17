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
        /**
         * Default constructor for the Vector class. This
         * implements an n-dimensional vector (in R^n), where
         * n is a natural number.
         * 
         * @param size The size of the vector, i.e. the value
         * of n.
         * @param entries A list of doubles containing
         * all components of the vector.
         * @return A new vector object.
        */
        Vector(const int size, double* entries);

        /**
         * Default destructor for any vector object.
        */
        ~Vector();

        /**
         * Obtain the i-th component of the vector
         * from left to right.
         * 
         * @param index The index which we are interested
         * in retrieving
         * @return The component at the i-th position.
        */
        double get_component(const int index);

        /**
         * Return the size of the vector, i.e. the
         * value of n for the vector space R^n
         * containing this vector object.
         * 
         * @return The size of the vector.
        */
        int get_size();

        /**
         * Compute the Lp norm of this vector object,
         * where p is a real parameter. Note that the Lp
         * norm is defined as:
         * 
         * |v|_p = (sum(|v_i|^p))^(1/p)
         * 
         * This is particularly useful when we are not
         * only interested in the Euclidian norm of this object.
         * 
         * @param p The real parameter for which we want to
         * compute the norm
         * @return The norm.
        */
        double norm(double p);

        /**
         * Return the Euclidian (L2) norm of this
         * vector. This function simply calls the Lp
         * norm implementation.
         * 
         * @return The Euclidian (L2) norm of the vector.
        */
        double norm();

        /**
         * Return the infinity-norm of this vector, i.e.
         * the maximum element within its components.
         * 
         * Note that one can easily prove that the infinity
         * norm returns the maximum element by dividing through
         * the maximum element's absolute valute and taking
         * the limit as p goes to infinity.
         * 
         * @return The infinity norm.
        */
        double infinity_norm();

        /**
         * Operator overloading for vector addition.
         * 
         * @param vec The vector which we are adding
         * onto our current vector.
         * @return A new vector object representing the
         * sum of the two vectors.
        */
        Vector operator+(const Vector& vec);

        /**
         * Operator overloading for vector subtraction.
         * 
         * @param vec The vector which will be subtracted 
         * from our current vector.
         * @return A new vector object representing the
         * difference of the two vectors.
        */
        Vector operator-(const Vector& vec);

        /**
         * Stringify the vector object for it to be
         * easily printed to console (especially for
         * debugging purposes), or for any other particular
         * uses.
         * 
         * Contains data regarding its size and elements.
         * 
         * @return The stringified version of the vector.
        */
        std::string to_string();
    };
}


#endif