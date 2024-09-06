# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Programs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# List of source files
set(SOURCES
        03-basic/01-hello-world.cpp
        03-basic/02-no-main-return.cpp
        03-basic/03-a-plus-b.cpp
        03-basic/04-compilation-error.cpp
        03-basic/05-global-vars-scopes.cpp
        03-basic/06-using-namespace.cpp
        03-basic/07-using-namespace-bad.cpp
        03-basic/08-compilers-differ.cpp
        03-basic/09-bits-stdcpp.cpp
        04-ub/01-uninitialized-vars.cpp
        04-ub/02-array-overflow.cpp
)

# Loop over each source file to create individual executables
foreach(SOURCE_FILE ${SOURCES})
    # Extract the name without the extension (e.g., main1, main2)
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)

    # Add executable for each source file
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
endforeach()
