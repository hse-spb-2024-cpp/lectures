# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Programs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# List of source files
set(SOURCES
        05-inheritance-extra/10-circle-ellipse.cpp
        05-inheritance-extra/02-pure-virtual-ctors.cpp
        05-inheritance-extra/01-virtual-in-ctors.cpp
        00-no-naive-threading/10-still-bad-toctou.cpp
        00-no-naive-threading/01-optimizer.cpp
        00-no-naive-threading/02-reordering.cpp
        00-no-naive-threading/03-volatile-bad.cpp
        04-rtti/01-typeid-basic.cpp
        04-rtti/02-typeid-operations.cpp
        04-rtti/04-dynamic-cast-ref.cpp
        04-rtti/03-dynamic-cast.cpp
        01-operator-bool/01-operator-bool-usage.cpp
        01-operator-bool/03-operator-explicit.cpp
        01-operator-bool/02-operator-implicit.cpp
        10-basics-extra/10-order-of-eval.cpp
        10-basics-extra/20-vector-bool.cpp
        10-basics-extra/02-floating-ops.cpp
        10-basics-extra/03-floating-bad.cpp
        10-basics-extra/01-floating.cpp
        10-basics-extra/11-interleaving.cpp
        10-basics-extra/12-vector-ub-before-cpp17.cpp
        10-basics-extra/04-long-long-vs-double.cpp
        10-basics-extra/13-short-circuit.cpp
        03-old-c/04-const-cast.cpp
)

# Loop over each source file to create individual executables
foreach(SOURCE_FILE ${SOURCES})
    # Extract the name without the extension (e.g., main1, main2)
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)

    # Add executable for each source file
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
endforeach()
