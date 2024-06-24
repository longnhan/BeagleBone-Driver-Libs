cmake_minimum_required(VERSION 3.5)
project(peripheral_driver_prj VERSION 1.0)

# Add preprocessor definitions
add_definitions(-DDEBUG)

# Set toolchain
set(CMAKE_C_COMPILER /home/nhan/projects/BBGW-L3G4200D/toolchain/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/test
    ${CMAKE_SOURCE_DIR}/peripheral_Driver
)

# Add subdirectories
add_subdirectory(test)
add_subdirectory(peripheral_Driver)

# Create the executable for 2 processes
add_executable(test_main test/main.c)

# Link libraries for 2 processes
target_link_libraries(test_main src_lib bb_driver_lib)

# Generate .map file for 2 processes
set_target_properties(test_main PROPERTIES LINK_FLAGS "-Wl,-Map=test_main.map")