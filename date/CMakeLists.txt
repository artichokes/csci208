cmake_minimum_required(VERSION 3.3)
project(date)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES Date.h Date.cpp main.cpp)
add_executable(date ${SOURCE_FILES})
