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

#ifndef __THMATH_LINE_
#define __THMATH_LINE_

#include "vector.h"
#include <string>

namespace thmath
{
    /**
     * Represents a line in three-dimensional space.
     */
    class Line
    {
    private:
        Vector* position_a;  /**< The position vector of a point on the line. */
        Vector* direction;   /**< The direction vector of the line. */
        
    public:

        /**
         * Constructor for the Line class. This
         * creates the line between the two given points.
         * 
         * @param point_a The first point.
         * @param point_b The second point.
        */
        Line(const Vector& point_a, const Vector& point_b);

        /**
         * Copy constructor for the line class.
         * 
         * @param other The line object to copy from.
        */
       Line(const Line& other);

        /**
         * Destructor for the Line class.
         */
        ~Line();

        /**
         * Get the direction vector of the line.
         * 
         * @return The direction vector of the line.
         */
        Vector get_direction() const;

        /**
         * Get a point on the line corresponding to a parameter lambda.
         * 
         * @param lambda The parameter representing a point on the line.
         * @return A vector representing a point on the line.
         */
        Vector get_point(double lambda) const;

        /**
         * Check if a point lies on the line.
         * 
         * @param point The point to check.
         * @return True if the point lies on the line, false otherwise.
         */
        bool contains(const Vector& point) const;

        /**
         * Calculate the distance between a point and the line.
         * 
         * @param point The point to calculate the distance to.
         * @return The distance between the point and the line.
         */
        double distance(const Vector& point) const;

        /**
         * Calculate the shortest distance between two lines.
         * 
         * @param line The other line.
         * @return The shortest distance between the two lines.
         */
        double distance(const Line& line) const;

        /**
         * Find the point of intersection between two lines.
         * 
         * @param line The other line to intersect with.
         * @return The point of intersection between the two lines.
         */
        Vector intersect(const Line& line) const;

        /**
         * Check if this line is perpendicular to another line.
         * 
         * @param line The other line to check against.
         * @return True if this line is perpendicular to the other line, false otherwise.
         */
        bool is_perpendicular(const Line& line) const;

        /**
         * Check if this line is parallel to another line.
         * 
         * @param line The other line to check against.
         * @return True if this line is parallel to the other line, false otherwise.
         */
        bool is_parallel(const Line& line) const;

        /**
         * Assignment operator overload for the line class
         * 
         * @param other The object to assign from.
         * @return A reference to the assigned object.
        */
        Line& operator=(const Line& other);

        /**
         * Equality operator overloading between
         * two lines.
         * 
         * @param other The object which shall be
         * checked with the current line.
         * @return Whether or not the two lines
         * are equal.
        */
        bool operator==(const Line& other) const;

        /**
         * Stringify the line and return. This
         * method can be used for debugging purposes.
         * 
         * @return The stringified line.
        */
        std::string to_string() const;
    };
}

#endif
