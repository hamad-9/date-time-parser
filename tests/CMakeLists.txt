cmake_minimum_required(VERSION 3.10)

# Define the test executable that includes both the test file and the source file needed
add_executable(date-time-parser-tests main_test.cpp ../src/utils.cpp)

# Include directories for header files
target_include_directories(date-time-parser-tests PRIVATE ../include)

# Include the testing module
include(CTest)

# Add tests
add_test(NAME AllTests COMMAND date-time-parser-tests)
