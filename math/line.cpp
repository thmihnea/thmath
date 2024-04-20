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

#include "line.h"
#include "vector.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream>

thmath::Line::Line(const thmath::Vector& point_a, const thmath::Vector& point_b)
{
    auto direction = point_b - point_a;
    this->position_a = new thmath::Vector(point_a.get_size(), point_a.get_entries());
    this->direction = new thmath::Vector(direction.get_size(), direction.get_entries());
}

thmath::Line::~Line()
{
    delete this->position_a;
    delete this->direction;
}

thmath::Vector thmath::Line::get_direction() const
{
    return *this->direction;
}

thmath::Vector thmath::Line::get_point(double lambda) const
{
    return (*this->position_a) + (*this->direction * lambda);
}

bool thmath::Line::contains(const thmath::Vector& point) const
{
    auto potential_direction = point - *this->position_a;
    return potential_direction.is_parallel(point);
}

double thmath::Line::distance(const thmath::Vector& point) const
{
    auto diff = point - *this->position_a;
    diff = diff.vector_product(*this->direction);
    return (diff *= (1 / this->direction->norm())).norm();
}

double thmath::Line::distance(const thmath::Line& line) const
{
    if (is_parallel(line))
    {
        return distance(*line.position_a);
    }

    auto normal = (*this->direction).vector_product(*line.direction).normalized();
    auto diff = *this->position_a - *line.position_a;
    return std::abs(
        diff.dot_product(normal)
    );
}

thmath::Vector thmath::Line::intersect(const Line& line) const
{
    if (is_parallel(line))
    {
        throw std::exception();
    }

    Vector positionDifference = *line.position_a - *position_a;
    Vector crossProduct1 = positionDifference.vector_product(line.get_direction());
    Vector crossProduct2 = direction->vector_product(line.get_direction());
    double lambda = crossProduct1.dot_product(crossProduct2) / std::pow(crossProduct2.norm(), 2);


    return get_point(lambda);
}

bool thmath::Line::is_perpendicular(const Line& line) const
{
    return (*this->direction).dot_product(*line.direction) == 0;
}

bool thmath::Line::is_parallel(const Line& line) const
{
    return (*this->direction).vector_product(*line.direction) == nullvec3;
}

thmath::Line::Line(const Line& other) {
    position_a = new thmath::Vector(*other.position_a);
    direction = new thmath::Vector(*other.direction);
}

thmath::Line& thmath::Line::operator=(const thmath::Line& other)
{
    if (this != &other)
    {
        delete this->position_a;
        delete this->direction;
        this->position_a = new thmath::Vector(*other.position_a);
        this->direction = new thmath::Vector(*other.direction);
    }
    return *this;
}

bool thmath::Line::operator==(const thmath::Line& other) const
{
    return is_parallel(other) && contains(*(other.position_a));
}

std::string thmath::Line::to_string() const
{
    std::ostringstream stream;
    stream << "Line={position_a=" << this->position_a->to_string() << ", direction=" << this->direction->to_string() << "}";
    return stream.str();
}