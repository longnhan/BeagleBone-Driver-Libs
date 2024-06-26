#include "bb_gpio.h"

void bb_gpio_init(gpio_st *ptr, char *pin, int direction)
{
    /*first setup for this pin*/
    bb_set_gpio_path(ptr, pin);
    /*export gpio*/
    int gpio_fd = open(GPIO_EXPORT, O_WRONLY);
    if (gpio_fd == -1)
    {
        fprintf(stderr, "Unable to open file\n");
        exit(EXIT_FAILURE);
    }
    /*create gpio direcotry*/
    if(write(gpio_fd, pin, strlrn(pin)) == -1)
    {
        fprintf(stderr, "Error to write to file\n");
        close(gpio_fd);
        exit(EXIT_FAILURE);
    }
    /*set pin direction*/
    if(write(gpio_fd, GPIO_PIN_10, sizeof(GPIO_PIN_10)) == -1)
    {
        fprintf(stderr, "Error to write to file\n");
        close(gpio_fd);
        exit(EXIT_FAILURE);
    }
    /*set default state*/
}

void bb_set_gpio_path(gpio_st *ptr, char *pin)
{
    /*set direction path*/
    size_t dir_path_len = strlen(GPIO_PATH) 
                            + strlen(pin) 
                            + strlen("/") 
                            + strlen("direction") + 1;
    ptr->fp_direction = (char *)malloc(dir_path_len);
    if(ptr->fp_direction == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    sprintf(ptr->fp_direction,"%s%s/direction",GPIO_PATH, pin);
    printf("direction path is: %s\n", ptr->fp_direction);
}

void bb_gpio_write()
{

}

void bb_gpio_read()
{

}

void bb_gpio_unexport(char *pin)
{
    int gpio_fd = open(GPIO_UNEXPORT, O_WRONLY);
    if (gpio_fd == -1)
    {
        fprintf(stderr, "Unable to open file\n");
        exit(EXIT_FAILURE);
    }
    /*unexport gpio direcotry*/
    if(write(gpio_fd, pin, strlrn(pin)) == -1)
    {
        fprintf(stderr, "Error to write to file\n");
        close(gpio_fd);
        exit(EXIT_FAILURE);
    }
    close(gpio_fd);
}

void bb_gpio_close(gpio_st *ptr, char *pin)
{
    /*unexport gpio*/
    bb_gpio_unexport(pin);
    /*free fp_active_low heap*/
    if(ptr->fp_active_low != NULL)
    {
        free(ptr->fp_active_low);
        ptr->fp_active_low = NULL;
    }
    /*free fp_direction heap*/
    if(ptr->fp_direction != NULL)
    {
        free(ptr->fp_direction);
        ptr->fp_direction = NULL;
    }
    /*free fp_edge heap*/
    if(ptr->fp_edge != NULL)
    {
        free(ptr->fp_edge);
        ptr->fp_edge = NULL;
    }
    /*free fp_label heap*/
    if(ptr->fp_label != NULL)
    {
        free(ptr->fp_label);
        ptr->fp_label = NULL;
    }
    /*free fp_value heap*/
    if(ptr->fp_value != NULL)
    {
        free(ptr->fp_value);
        ptr->fp_value = NULL;
    }
}