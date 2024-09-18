cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 - DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-o3 -DNDEBUG -s")

# Set the project name
project(writer)

# Incloude the current directory for header files
include_directories(include)

# Add the executable
add_executable(writer
                src/main.c
                src/writer.c)