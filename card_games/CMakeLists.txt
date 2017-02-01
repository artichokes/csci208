cmake_minimum_required(VERSION 3.3)
project(deck)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Card.h Card.cpp Deck.h Deck.cpp War.h War.cpp BlackJack.cpp BlackJack.h)
add_executable(deck ${SOURCE_FILES} main.cpp)
add_executable(deck_test ${SOURCE_FILES} test.cpp)

target_link_libraries(deck)
target_link_libraries(deck_test gtest)
