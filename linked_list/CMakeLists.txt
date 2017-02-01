cmake_minimum_required(VERSION 3.3)
project(linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp LinkedList.h Node.h)
add_executable(linked_list ${SOURCE_FILES})
