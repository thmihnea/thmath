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

#ifndef __THMATH_MESSAGES_
#define __THMATH_MESSAGES_

#pragma once

constexpr char* ILLEGAL_ACCESS_MESSAGE = "Attempted to perform an access into a non-existant component of the vector - check the index again.";
constexpr char* DIFFERENT_SIZE_MESSAGE = "Attempted to perform an operation on objects of different sizes - since they do not belong to the same set, the operation is undefined.";

#endif