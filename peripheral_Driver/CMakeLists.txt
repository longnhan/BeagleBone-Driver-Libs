# peripheral_Driver/CMakeLists.txt

# Add the source files in this directory
set(BEAGLEBONE_DRIVER_FILES
    bb_i2c.c
    bb_i2c.h
    bb_gpio.c
    bb_gpio.h
)

# Create a library from these files
add_library(bb_driver_lib ${BEAGLEBONE_DRIVER_FILES})

# Specify include directories for this target
target_include_directories(bb_driver_lib PUBLIC ${CMAKE_SOURCE_DIR}/peripheral_Driver)
