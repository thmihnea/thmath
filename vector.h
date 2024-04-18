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

#define nullvec3 thmath::Vector{0, 0, 0}
#define nullvec2 thmath::Vector{0, 0}

#include <string>

namespace thmath
{
    class Vector
    {
    private:
        double* entries;
        size_t size;

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
        Vector(const size_t size, double* entries);

        /**
         * Initializer list constructor for the Vector class.
         * This allows the object to be constructed by initializing
         * the objects in a list directly, without having
         * to specify a size_t.
         * 
         * @param entries The entries which shall be in the
         * vector.
         * @return A new vector object.
        */
        Vector(std::initializer_list<double> entries);

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
        double get_component(const int index) const;

        /**
         * Return the size of the vector, i.e. the
         * value of n for the vector space R^n
         * containing this vector object.
         * 
         * @return The size of the vector.
        */
        size_t get_size() const;

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
        double norm(double p) const;

        /**
         * Return the Euclidian (L2) norm of this
         * vector. This function simply calls the Lp
         * norm implementation.
         * 
         * @return The Euclidian (L2) norm of the vector.
        */
        double norm() const;

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
        double infinity_norm() const;

        /**
         * Perform the dot product between two
         * vectors - note that in the vector space
         * R^n this returns a real value.
         * 
         * @param vec The vector which should be
         * dotted (scalar product) with the current
         * vector object.
         * @return A real value representing the
         * scalar product between the two quantities.
        */
        double dot_product(const Vector& vec) const;

        /**
         * Perform the vector product between the
         * two given vector objects, and return a
         * new vector object that represents this
         * operation (cross product).
         * 
         * @param vec The vector which we are
         * crossing with the current one.
         * @return A new vector object representing
         * the cross product between the two vectors.
        */
        Vector vector_product(const Vector& vec) const;

        /**
         * Multiplies the given vector by a real parameter,
         * effectively re-scaling it.
         * 
         * @param lambda The amount by which the vector
         * shall be rescaled.
         * @return The newly edited vector. Note that this
         * changes the vector itself, rather than creating
         * a new instance.
        */
        Vector& scale(double lambda);

        /**
         * Normalizes the vector by its Lp norm.
         * 
         * @param p The parameter which shall be 
         * used in the Lp norm computation.
         * @return The same vector object, but
         * normalized by its Lp norm.
        */
        Vector& normalized(double p);

        /**
         * Normalizes the vector by its Euclidian norm.
         * 
         * @return The same vector object, but
         * normalized by its L2 norm.
        */
        Vector& normalized();

        /**
         * Return the angle between two n-dimensional
         * vectors. For R^2 and R^3, this is obvious
         * and intuitive; however, for a general R^n
         * vector space, we define the angle as the dot product
         * over the vectors' product of L2 norms.
         * 
         * @param vec The other vector which we are
         * measuring the angle with respect to.
         * @param cosine Whether or not the cosine shall
         * be returned instead of the angle. If true,
         * we return the cosine. It is by default set to false.
         * @return The angle between the two vectors.
        */
        double angle(const Vector& vec, bool cosine = false) const;

        /**
         * Check whether or not the two given vectors
         * are parallel. Note that this simply checks
         * whether there exists a constant k such that
         * vec_2 = k * vec_1, essentially.
         * 
         * @param vec The vector which we are checking
         * parallelism for.
         * @return Whether or not they are parallel.
        */
        bool is_parallel(const Vector& vec) const;

        /**
         * Check whether or not the two given vectors
         * are perpendicular. Note that this simply checks
         * whether their scalar product is null.
         * 
         * @param vec The vector which we are checking
         * perpendicularity with.
         * @return Whether or not they are perpendicular.
        */
        bool is_perpendicular(const Vector& vec) const;

        /**
         * Operator overloading for vector addition.
         * 
         * @param vec The vector which we are adding
         * onto our current vector.
         * @return A new vector object representing the
         * sum of the two vectors.
        */
        Vector operator+(const Vector& vec) const;

        /**
         * Operator overloading for vector addition,
         * but without generating a new vector object.
         * Rather, the result is added to the current vector.
         * 
         * @param vec The vector which shall be added.
         * @return The modified vector.
        */
        Vector& operator+=(const Vector& vec);

        /**
         * Operator overloading for vector subtraction.
         * 
         * @param vec The vector which will be subtracted 
         * from our current vector.
         * @return A new vector object representing the
         * difference of the two vectors.
        */
        Vector operator-(const Vector& vec) const;

        /**
         * Operator overloading for vector subtraction,
         * but without generating a new vector object.
         * Rather, the result is subtracted from the current vector.
         * 
         * @param vec The vector which shall be subtracted.
         * @return The modified vector.
        */
        Vector& operator-=(const Vector& vec);

        /**
         * Operator overloading for vector equality.
         * 
         * @param vec The vector which will be checked
         * against our current vector.
         * @return Whether or not the two vectors are
         * equal component-wise.
        */
        bool operator==(const Vector& vec) const;

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
        std::string to_string() const;
    };
}

#endif