/*
MIT License

Copyright (c) 2020 Steffen S.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _MBED_EXT_VECTOR_H_
#define _MBED_EXT_VECTOR_H_

#include <math.h>

/**
 * A 2 dimensional vector
 */
template<class T>
struct Vector2 {
    T x;
    T y;
};

/**
 * Gets the length of a 2 dimensional vector
 * @param v the vector
 * @return length of v 
 */
#define vect2_len(v) (sqrt(pow(v.x, 2) + pow(v.y, 2)))
/**
 * Performs a scalar muliplication on a 2 dimensional vector
 * @param a the scalar
 * @param v the vector
 */
#define vect2_scalar_mult(a, v) (v.x = a * v.x; v.y = a * v.y;)
/**
 * Calculates the dot product between two 2 dimensional vectors
 * @param v1 the first vector
 * @param v2 the second vector
 * @return the dot product between v1 and v2
 */
#define vect2_dot_product(v1, v2) (v1.x * v2.x + v1.y * v2.y)

/**
 * A 3 dimensional vector
 */
template<class T>
struct Vector3
{
    T x;
    T y;
    T z;
};

/**
 * Gets the length of a 3 dimensional vector
 * @param v the vector
 * @return length of v 
 */
#define vect3_len(v) (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)))
/**
 * Performs a scalar muliplication on a 3 dimensional vector
 * @param a the scalar
 * @param v the vector
 */
#define vect3_scalar_mult(a, v) (v.x = a * v.x; v.y = a * v.y; v.z = a * v.z;)
/**
 * Calculates the dot product between two 3 dimensional vectors
 * @param v1 the first vector
 * @param v2 the second vector
 * @return the dot product between v1 and v2
 */
#define vect3_dot_product(v1, v2) (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z)
/**
 * Calculates the cross product betwenn two 3 dimensional vectors
 * @param v1 the first vector
 * @param v2 the second vector
 * @return the cross product between v1 and v2
 */
#define vect3_cross_product(v1, v2) {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x}

/**
 * A 4 dimensional vector
 */
template<class T>
struct Vector4
{
    T x;
    T y;
    T z;
    T t;
};

/**
 * Gets the length of a 4 dimensional vector
 * @param v the vector
 * @return length of v 
 */
#define vect4_len(v) (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.t, 2)))
/**
 * Performs a scalar muliplication on a 4 dimensional vector
 * @param a the scalar
 * @param v the vector
 */
#define vect4_scalar_mult(a, v) (v.x = a * v.x; v.y = a * v.y; v.z = a * v.z; v.t = a * v.t;)

#endif
