#ifndef _BB_I2C_H_
#define _BB_I2C_H_

#include <linux/i2c-dev.h>
#include <linux/mmc/ioctl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BBGW_BOARD

#ifdef BBGW_BOARD
#define I2C_CHAR_DEVICE_0   "/dev/i2c-0"
#define I2C_CHAR_DEVICE_1   "/dev/i2c-1"
#define I2C_CHAR_DEVICE_2   "/dev/i2c-2"
#endif /*BBGW_BOARD*/

#ifdef BBB_BOARD
#endif /*BBB_BOARD*/

typedef struct i2c_st
{
    int i2c_fd;
    char *i2c_char;
    int slave_addr;
};


extern void bb_i2cInit(struct i2c_st *ptr);
extern void bb_i2cClose(struct i2c_st *ptr);
extern uint8_t bb_getI2cData(struct i2c_st *ptr, uint8_t regAddress, uint8_t *buf, uint8_t size);
extern uint8_t bb_sendI2cData(struct i2c_st *ptr, uint8_t regAddress, uint8_t cmd);

#endif /*_BB_I2C_H_*/