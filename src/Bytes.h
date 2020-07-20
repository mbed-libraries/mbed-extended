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

#ifndef _MBED_EXT_BYTES_H_
#define _MBED_EXT_BYTES_H_

/* Bitwise Operations */


/**
 * Inverts the value
 * @param a the value to invert
 * @return the inverted value
 */
#define bnot(a) (~a)

/**
 * Applies the bitwise AND operation to two values
 * @param a value A
 * @param b value B
 * @return A & B
 */
#define band(a, b) (a & b)

/**
 * Applies the bitwise OR operation to two values
 * @param a value A
 * @param b value B
 * @return A | B
 */
#define bor(a, b) (a | b)

/**
 * Applies the bitwise XOR operation to two values
 * @param a value A
 * @param b value B
 * @return A ^ B
 */
#define bxor(a, b) (a ^ b)

/**
 * Shifts the value a specific amount of positions to the left
 * @param a the value to shift
 * @param n amount of positions to shift
 * @return the shifted value (a << n)
 */
#define lshift(a, n) (a << n)

/**
 * Shifts the value a specific amount of positions to the right
 * @param a the value to shift
 * @param n amount of positions to shift
 * @return the shifted value (a >> n)
 */
#define rshift(a, n) (a >> n)


/* Bit manipulation */


/**
 * Gets the value of a bit at a specific position
 * @param v the value that is read
 * @param n the bit position to read, where 0 identifies the LSB
 * @return the bit value at position n
 */
#define bit_read(v, n) (((v) >> (n)) & 0x01)

/**
 * Sets the value of the bit at a specific position to 1
 * @param v the value that is manipulated
 * @param n the bit position to write, where 0 identifies the LSB
 */
#define bit_set(v, n) ((v) |= (1 << (n)))

/**
 * Sets the value of the bit at a specific position to 0
 * @param v the value that is manipulated
 * @param n the bit position to write, where 0 identifies the LSB
 */
#define bit_clear(v, n) ((v) &= ~(1 << (n)))

/**
 * Sets the value of a bit at a specific position
 * @param v the value that is manipulated
 * @param n the bit position to write, where 0 identifies the LSB
 * @param bit the value of the bit, either 1 or 0
 */
#define bit_write(v, n, bit) (bit ? bit_set(v, n) : bit_clear(v, n))

/**
 * Toggles the value of a bit at a specific position
 * @param v the value that is manipulated
 * @param n the bit position to toggle, where 0 identifies the LSB
 */
#define bit_toggle(v, n) (bit_read(v, n) ? bit_clear(v, n) : bit_set(v, n))


/* Byte combination / splitting */


/**
 * Combines two 8-bit values (uint8_t) to a uint16_t value
 * @param high the higher byte
 * @param low the lower byte
 * @return the uint16_t that is combined from the two input values 
 */
#define combine_uint16(high, low) (((uint16_t)high << 8) | low)

/**
 * Combines four 8-bit values (uint8_t) to a uint32_t value
 * @param b1 byte 1
 * @param b2 byte 2
 * @param b3 byte 3
 * @param b4 byte 4
 * @return the uint32_t that is combined from the four input values 
 */
#define combine_uint32(b1, b2, b3, b4) ((uint32_t)(b1 | (b2 << 8) | (b3 << 16) | (b4 << 24)))

/**
 * Reads the higher order byte from a 16-bit value
 * @param v the 16-bit value
 * @return the high byte
 */
#define high_byte(v) (v & 0xFF00)

/**
 * Reads the lower order byte from a 16-bit value
 * @param v the 16-bit value
 * @return the low byte
 */
#define low_byte(v) (v & 0x00FF)

/**
 * Casts uint16_t to int16_t
 * @param uint the uint16_t to cast
 * @return the casted int16_t value
 */
#define uint16_to_int16(uint) (reinterpret_cast<int16_t&>(uint))

/**
 * Casts uint32_t to int32_t
 * @param uint the uint32_t to cast
 * @return the casted int32_t value
 */
#define uint32_to_int32(uint) (reinterpret_cast<int32_t&>(uint))

#endif