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

#ifndef _MBED_EXT_I2C_HELPER_H_
#define _MBED_EXT_I2C_HELPER_H_

#include <mbed.h>
#include <Bytes.h>

/**
 * Selects a register via I2C without terminating the transmission
 * @param i2c the I2C device
 * @param slaveAddress the 7-bit address of the slave
 * @param regAdress the address of the register to select
 */
#define I2C_SELECT_REG(i2c, slaveAddress, regAddress) if (i2c->write(slaveAddress, (const char *)&regAddress, 1, true) != 0){return I2C_ERROR;} 

/**
 * Converts a 7-bit I2C Address to an 8-bit I2C address
 * @param addr7bit the 7-bit address
 * @return the 8-bit address
 */
#define I2C_ADDR_8BIT(addr7bit) (addr7bit << 1)

/**
 * Return codes for I2C operations
 */
typedef enum {
    /**
     * Successfully executed
     */
    I2C_OK = 1,
    /**
     * Something went wrong
     */
    I2C_ERROR = 0
}i2c_return_code;

/**
 * Provides utility methods for communication using the I2C master interface
 */
class I2CUtil
{

public:
    /**
     * Reads a single byte
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param data pointer to the location the read byte is stored
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code readByte(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t * data);

    /**
     * Writes a single byte
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param data the byte to write
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code writeByte(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t data);

    /**
     * Reads multiple bytes starting by a given register
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param data pointer to the location the read bytes are stored
     * @param numBytes the number of bytes to read
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code readBytes(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t * data, size_t numBytes);

    /**
     * Writes multiple bytes
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param data the data to writes
     * @param numBytes the number of bytes to write
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code writeBytes(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, const uint8_t * data, size_t numBytes);

    /**
     * Reads a single bit from a register
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param bitPos the position of the bit (0 = LSB)
     * @param value pointer to the location the read bit is stored
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code readBit(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t bitPos, bool * value);

    /**
     * Writes a single bit to a register
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param bitPos the position of the bit (0 = LSB)
     * @param value the bit value to write
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code writeBit(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t bitPos, bool value);

    /**
     * Read multiple bits from a register
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param registerMask mask for the bits to read. When a bit is set in the mask, the corresponding bit in the register will be read
     * @param data pointer to the location the read bits are stored 
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code readBits(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t registerMask, uint8_t * data);

    /**
     * Writes multiple bits to a register
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @param registerAddress the address of the register to read
     * @param registerMask mask for the bits to read. When a bit is set in the mask, the corresponding bit in the register will be overwritten
     * @param data the bits to write
     * @return I2C_OK when the operation was successfull, I2C_ERROR otherwise
     */
    static i2c_return_code writeBits(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t registerMask, uint8_t data);

    /**
     * Probes a specific I2C address to check whether a device is connected
     * @param i2c the I2C device to use
     * @param slaveAddress the 7-bit address of the slave
     * @return true if there is a device available at the address, false if there is no device available or an I2C error occurred
     */
    static bool probeAddress(I2C * i2c, uint8_t slaveAddress);
private:
    I2CUtil () {};
};


#endif