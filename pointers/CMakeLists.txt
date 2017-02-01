cmake_minimum_required(VERSION 3.3)
project(pointers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES pointers.cpp)
add_executable(pointers ${SOURCE_FILES})
