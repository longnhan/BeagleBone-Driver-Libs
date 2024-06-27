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
#define BB_GPIO_SET         (uint8_t)1
#define BB_GPIO_RESET       (uint8_t)0
/*Define GPIO system files*/
#define GPIO_PATH           "/sys/class/gpio/gpio"
#define GPIO_EXPORT         "/sys/class/gpio/export"
#define GPIO_UNEXPORT       "/sys/class/gpio/unexport"
/*Define direction*/
#define GPIO_INPUT          "int"
#define GPIO_OUTPUT         "out"

#define GPIO_PIN_10         "10"

#endif /*BBGW_BOARD*/

typedef struct
{
    char *fp_value;
    char *fp_direction;
    char *fp_edge;
    char *fp_label;
    char *fp_active_low;
}gpio_st;


/*Public function*/
void bb_gpio_read();
void bb_gpio_write();
void bb_gpio_set_direction(gpio_st *ptr, const char *direction);
void bb_gpio_close(gpio_st *ptr, const char *pin);
void bb_gpio_open(gpio_st *ptr, const char *pin, const char *direction);

/*Local function*/
void bb_gpio_export(const char *pin);
void bb_gpio_unexport(const char *pin);
void bb_set_gpio_path(gpio_st *ptr, const char *pin);

#endif /*_BB_GPIO_H_*/