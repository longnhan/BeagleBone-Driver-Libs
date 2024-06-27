#include "main.h"


int main(void)
{
#ifdef  GPIO_TEST
    gpio_st gpio10;
    bb_gpio_open(&gpio10, GPIO_PIN_10, GPIO_OUTPUT);
    // bb_gpio_close(&gpio10, GPIO_PIN_10);
#endif /*GPIO_TEST*/

#ifdef  I2C_TEST
    uint8_t devicename_reg = 0x0F;
    uint8_t buf[1]={0};
    i2c_st testI2c;
    testI2c.i2c_char = I2C_CHAR_DEVICE_2;
    testI2c.slave_addr = 0x69;

    bb_i2cInit(&testI2c);
    sleep(1);
    bb_i2c_master_getData(&testI2c, &devicename_reg, buf, 1);
    printf("device name is: %d\n", buf[0]);
    bb_i2cClose(&testI2c);
#endif /*TEST_I2C*/
    return 0;    
}
