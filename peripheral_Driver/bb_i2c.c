#include "bb_i2c.h"

void bb_i2cInit(struct i2c_st *ptr)
{
    /*Open the I2C bus*/
    if ((ptr->i2c_fd = open(ptr->i2c_char, O_RDWR)) < 0) 
    {
        fprintf(stderr, "Failed to open the bus\n");
        exit(EXIT_FAILURE);
    }
    /*Set the I2C slave address*/
    if (ioctl(ptr->i2c_fd, I2C_SLAVE, ptr->slave_addr) < 0) 
    {
        fprintf(stderr, "Failed to acquire bus access and/or talk to slave\n");
        exit(EXIT_FAILURE);
    }
}

void bb_i2cClose(struct i2c_st *ptr)
{
    close(ptr->i2c_fd);
}

uint8_t bb_getI2cData(struct i2c_st *ptr, uint8_t regAddress, uint8_t *buf, uint8_t size)
{
    uint8_t ret = 0;

    write(ptr->i2c_fd, &regAddress, 1);
    ret = read(ptr->i2c_fd, buf, size);
    return ret;
}

uint8_t bb_sendI2cData(struct i2c_st *ptr, uint8_t regAddress, uint8_t cmd)
{
    uint8_t ret = 0;
    uint8_t send_Buf[2]={0};
    send_Buf[0] = regAddress;
    send_Buf[1] = cmd;

    ret = write(ptr->i2c_fd, send_Buf, 2);
    return ret;
}