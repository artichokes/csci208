cmake_minimum_required(VERSION 3.3)
project(games)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

include_directories(include)
set(SOURCE_FILES
        include/Card.h
        include/Deck.h
        include/BlackJack.h
        include/War.h
        include/MagicCard.h
        include/Tool.h
        include/Rock.h
        include/Paper.h
        include/Scissors.h
        include/RPS.h
        include/Node.h
        include/LinkedList.h
        include/Stack.h
        include/Hand.h
        include/DiscardPile.h
        include/CrazyEights.h
        src/Card.cpp
        src/Deck.cpp
        src/BlackJack.cpp
        src/War.cpp
        src/MagicCard.cpp
        src/Tool.cpp
        src/Rock.cpp
        src/Paper.cpp
        src/Scissors.cpp
        src/RPS.cpp
        src/Hand.cpp
        src/DiscardPile.cpp
        src/CrazyEights.cpp)
add_executable(games ${SOURCE_FILES} main.cpp)
add_executable(games_test ${SOURCE_FILES} test.cpp)

target_link_libraries(games)
target_link_libraries(games_test ${GTEST_BOTH_LIBRARIES})

add_test(AllTests games_test)
