cmake_minimum_required(VERSION 3.10)

project(DateTimeParser VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify include directories
include_directories(include)

# Add the executable
add_executable(DateTimeParser src/main.cpp src/utils.cpp src/DateTime.cpp)

enable_testing()
add_subdirectory(tests)
