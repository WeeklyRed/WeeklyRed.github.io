cmake_minimum_required(VERSION 3.5.1)
# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# used internally by CMake to identify your project
project(a4LowerUpper)
# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)
# Add the main executable
add_executable(main_1 src/main.cpp src/array_bounds.cpp)
add_executable(test_1 tests/test.cpp src/array_bounds.cpp)

target_include_directories(test_1 PRIVATE ${PROJECT_SOURCE_DIR}/include)

enable_testing()

add_test(Name test_1 COMMAND test_1)
