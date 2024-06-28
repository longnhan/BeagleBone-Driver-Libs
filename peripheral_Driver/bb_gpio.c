#include "bb_gpio.h"

void bb_gpio_open(gpio_st *ptr, const char *pin, const char *direction)
{
    /*-----------------------------------------------------*/
    /*first setup for this pin*/
    /*-----------------------------------------------------*/
    bb_set_gpio_path(ptr, pin);
    
    /*-----------------------------------------------------*/
    /*export gpio*/
    /*-----------------------------------------------------*/
    bb_gpio_export(ptr);
    
    /*-----------------------------------------------------*/
    /*set pin direction*/
    /*-----------------------------------------------------*/
    bb_gpio_set_direction(ptr, direction);
    
    /*set default state*/
    /*-----------------------------------------------------*/
    /*End*/
    /*-----------------------------------------------------*/
}

void bb_set_gpio_path(gpio_st *ptr, const char *pin)
{
    /*-----------------------------------------------------*/
    /*set gpio pin*/
    /*-----------------------------------------------------*/
    ptr->gpio_pin = pin;
    
    /*-----------------------------------------------------*/
    /*set direction path*/
    /*-----------------------------------------------------*/
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

    /*-----------------------------------------------------*/
    /*set value path*/
    /*-----------------------------------------------------*/
    size_t val_path_len = strlen(GPIO_PATH) 
                            + strlen(pin) 
                            + strlen("/") 
                            + strlen("value") + 1;
    ptr->fp_value = (char *)malloc(val_path_len);
    if(ptr->fp_value == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    sprintf(ptr->fp_value,"%s%s/value",GPIO_PATH, pin);
    printf("value path is: %s\n", ptr->fp_value);
    /*-----------------------------------------------------*/
    /*End*/
    /*-----------------------------------------------------*/
}

void bb_gpio_write(gpio_st *ptr, char *state)
{
    int value_fd = open(ptr->fp_value, O_WRONLY);
    if (value_fd == -1)
    {
        fprintf(stderr, "Unable to open file direction\n");
        exit(EXIT_FAILURE);
    }

    if(write(value_fd, state, strlen(state)) == -1)
    {
        fprintf(stderr, "Error to write to direction\n");
        exit(EXIT_FAILURE);
    }
    close(value_fd);
}

void bb_gpio_read(gpio_st *ptr)

{

}

void bb_gpio_set_direction(gpio_st *ptr, const char *direction)
{
    int direction_fd = open(ptr->fp_direction, O_WRONLY);
    if (direction_fd == -1)
    {
        fprintf(stderr, "Unable to open file direction\n");
        exit(EXIT_FAILURE);
    }

    if(write(direction_fd, direction, strlen(direction)) == -1)
    {
        fprintf(stderr, "Error to write to direction\n");
        exit(EXIT_FAILURE);
    }
    close(direction_fd);
}

void bb_gpio_export(gpio_st *ptr)
{
    int export_fd = open(GPIO_EXPORT, O_WRONLY);
    if (export_fd == -1)
    {
        fprintf(stderr, "Unable to open file export\n");
        exit(EXIT_FAILURE);
    }
    if(write(export_fd, ptr->gpio_pin, strlen(ptr->gpio_pin)) == -1)
    {
        if(write(export_fd, ptr->gpio_pin, strlen(ptr->gpio_pin)) == -1)
        {
            fprintf(stderr, "Error to export\n");
            exit(EXIT_FAILURE);
        }
    }
    close(export_fd);
}

void bb_gpio_unexport(gpio_st *ptr)
{
    /*-----------------------------------------------------*/
    /*Open unexport file*/
    /*-----------------------------------------------------*/
    int unexport_fd = open(GPIO_UNEXPORT, O_WRONLY);
    if (unexport_fd == -1)
    {
        fprintf(stderr, "Unable to open file unexport\n");
        exit(EXIT_FAILURE);
    }

    /*-----------------------------------------------------*/
    /*unexport gpio direcotry*/
    /*-----------------------------------------------------*/
    if(write(unexport_fd, ptr->gpio_pin, strlen(ptr->gpio_pin)) == -1)
    {
        fprintf(stderr, "Error to unexport\n");
        close(unexport_fd);
        exit(EXIT_FAILURE);
    }
    close(unexport_fd);
    
    /*-----------------------------------------------------*/
    /*End*/
    /*-----------------------------------------------------*/
}

void bb_gpio_close(gpio_st *ptr, const char *pin)
{
    /*-----------------------------------------------------*/
    /*unexport gpio*/
    /*-----------------------------------------------------*/
    bb_gpio_unexport(ptr);
    
    /*-----------------------------------------------------*/
    /*free fp_direction heap*/
    /*-----------------------------------------------------*/
    if(ptr->fp_direction != NULL)
    {
        free(ptr->fp_direction);
        ptr->fp_direction = NULL;
    }

    /*-----------------------------------------------------*/
    /*free fp_value heap*/
    /*-----------------------------------------------------*/
    if(ptr->fp_value != NULL)
    {
        free(ptr->fp_value);
        ptr->fp_value = NULL;
    }
}