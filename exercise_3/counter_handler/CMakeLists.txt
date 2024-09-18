cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 - DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-o3 -DNDEBUG -s")

# Set the project name
project(counter_handler)

# Incloude the current directory for header files
include_directories(include)

# Add the exectuable
add_executable(counter_handler
                src/main.c
                src/counter_handler.c)