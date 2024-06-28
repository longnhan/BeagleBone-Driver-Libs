#ifndef _BB_GPIO_H_
#define _BB_GPIO_H_

#include <sys/ioctl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BBGW_BOARD

#ifdef BBGW_BOARD

/*Define GPIO state*/
#define BB_GPIO_SET         "1"
#define BB_GPIO_RESET       "0"
/*Define GPIO system files*/
#define GPIO_PATH           "/sys/class/gpio/gpio"
#define GPIO_EXPORT         "/sys/class/gpio/export"
#define GPIO_UNEXPORT       "/sys/class/gpio/unexport"
/*Define direction*/
#define GPIO_INPUT          "int"
#define GPIO_OUTPUT         "out"

#define GPIO_PIN_10         "10"
#define GPIO_PIN_60         "60"

#endif /*BBGW_BOARD*/

typedef struct
{
    char *fp_value;
    char *fp_direction;
    char *fp_edge;
    char *fp_label;
    char *fp_active_low;
    const char *gpio_pin;
}gpio_st;


/*Public function*/
void bb_gpio_read(gpio_st *ptr);
void bb_gpio_write(gpio_st *ptr, char *state);
void bb_gpio_close(gpio_st *ptr, const char *pin);
void bb_gpio_open(gpio_st *ptr, const char *pin, const char *direction);

/*Local function*/
void bb_gpio_export(gpio_st *ptr);
void bb_gpio_unexport(gpio_st *ptr);
void bb_set_gpio_path(gpio_st *ptr, const char *pin);
void bb_gpio_set_direction(gpio_st *ptr, const char *direction);

#endif /*_BB_GPIO_H_*/