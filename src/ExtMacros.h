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

#ifndef _MBED_EXT_MACROS_H_
#define _MBED_EXT_MACROS_H_

#define HIGH 1
#define LOW 0

/**
 * Gets the maximum between two values
 * @param a value A
 * @param b value B
 * @return B if A < B, otherwise A
 */
#define max(a, b) (a < b ? b  : a)
/**
 * Gets the minimun between two values
 * @param a value A
 * @param b value B
 * @return A if A < B, otherwise B
 */
#define min(a, b) (a < b ? a : b)

/**
 * Maps a value from one range to another.
 * @param x the value to map
 * @param in_min the lower bound of the input range
 * @param in_max the upper bound of the input range
 * @param out_min the lower bound of the output range
 * @param out_max the upper bound of the output range
 * @return the mapped value
 */
#define map(x, in_min, in_max, out_min, out_max) ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

/**
 * Contrains the value to be within a range
 * @param x the value to restrain
 * @param lowerBound the lower bound of the range
 * @param upperBound the upper bound of the range
 * @return lowerBound if x < lowerBound, upperBound if x > upperBound, x otherwise
 */
#define constrain(x, lowerBound, upperBound) (x > lowerBound ? (x < upperBound ? x : upperBound) : lowerBound)

#endif