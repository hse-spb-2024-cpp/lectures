# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Programs2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall)

# List of source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")

set(i 0)
# Loop over each source file to create individual executables
foreach(SOURCE_FILE ${SOURCES})

    # Extract the name without the extension (e.g., main1, main2)
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)

    # Add executable for each source file
    add_executable(${EXEC_NAME}-${i} ${SOURCE_FILE})

    math(EXPR i "${i} + 1")

endforeach()
