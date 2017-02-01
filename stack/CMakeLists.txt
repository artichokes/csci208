cmake_minimum_required(VERSION 3.3)
project(stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES Node.h Stack.h)
add_executable(reverse ${SOURCE_FILES} reverse.cpp)
add_executable(calculator ${SOURCE_FILES} calculator.cpp)