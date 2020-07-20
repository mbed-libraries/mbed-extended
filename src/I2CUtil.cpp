#include <I2CUtil.h>

i2c_return_code I2CUtil::readByte(I2C * i2c, uint8_t slaveAddress,  uint8_t registerAddress, uint8_t * data) {
    return readBytes(i2c, slaveAddress, registerAddress, data, 1);
}

i2c_return_code I2CUtil::writeByte(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t data) {
    return writeBytes(i2c, slaveAddress, registerAddress, &data, 1);
}

i2c_return_code I2CUtil::readBytes(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t * data, size_t numBytes) {
    // select register
    I2C_SELECT_REG(i2c, I2C_ADDR_8BIT(slaveAddress), registerAddress);

    // read desired data
    if (i2c->read(I2C_ADDR_8BIT(slaveAddress), (char *)data, numBytes) != 0){
        return I2C_ERROR;
    };

    return I2C_OK;
}

i2c_return_code I2CUtil::writeBytes(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, const uint8_t * data, size_t numBytes) {
    // select register
    I2C_SELECT_REG(i2c, I2C_ADDR_8BIT(slaveAddress), registerAddress);

    // write desired data
    if (i2c->write(I2C_ADDR_8BIT(slaveAddress), (const char *)data, numBytes) != 0) {
        return I2C_ERROR;
    }

    return I2C_OK;
}

i2c_return_code I2CUtil::readBit(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t bitPos, bool * value) {
    uint8_t byte;

    // read the whole register byte
    if (readByte(i2c, slaveAddress, registerAddress, &byte) != I2C_OK) {
        return I2C_ERROR;
    }

    // read bit from byte
    
    *value = bit_read(byte, bitPos);

    return I2C_OK;
}

i2c_return_code I2CUtil::writeBit(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t bitPos, bool value) {
    uint8_t byte;

    // read the whole register byte
    if (readByte(i2c, slaveAddress, registerAddress, &byte) != I2C_OK) {
        return I2C_ERROR;
    }

    // set the bit value in the read byte
    byte = bit_write(byte, bitPos, value);

    // write modified byte back via i2c
    return writeByte(i2c, slaveAddress, registerAddress, byte);
}

bool I2CUtil::probeAddress(I2C * i2c, uint8_t slaveAddress) {
    return !i2c->write(I2C_ADDR_8BIT(slaveAddress), nullptr, 0);
}

i2c_return_code I2CUtil::readBits(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t registerMask, uint8_t * data) {
    uint8_t byte;

    // read the whole register byte
    if (readByte(i2c, slaveAddress, registerAddress, &byte) != I2C_OK) {
        return I2C_ERROR;
    }

    // will remove all bits exept the bits in the mask
    byte &= registerMask;
    *data = byte;

    return I2C_OK;
}

i2c_return_code I2CUtil::writeBits(I2C * i2c, uint8_t slaveAddress, uint8_t registerAddress, uint8_t registerMask, uint8_t data) {
    uint8_t byte;

    // read the whole register byte
    if (readByte(i2c, slaveAddress, registerAddress, &byte) != I2C_OK) {
        return I2C_ERROR;
    }

    byte = (byte & (0xff ^ registerMask)) | (data & registerMask);

    return writeByte(i2c, slaveAddress, registerAddress, byte);
}