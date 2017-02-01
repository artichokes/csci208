cmake_minimum_required(VERSION 3.3)
project(csci208)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp)
add_executable(csci208 ${SOURCE_FILES})

add_subdirectory(pointers)
add_subdirectory(date)
add_subdirectory(inheritance)
add_subdirectory(card_games)
add_subdirectory(templates)
add_subdirectory(linked_list)
add_subdirectory(stack)
add_subdirectory(recursion)
