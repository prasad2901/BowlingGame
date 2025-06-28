cmake_minimum_required(VERSION 3.10)
project(BowlingGame)

set(CMAKE_CXX_STANDARD 17)

# Enable Code Coverage if requested
option(CODE_COVERAGE "Enable coverage reporting" ON)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Code coverage enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Main game executable
add_executable(BowlingGame
    main.cpp
    Frame.cpp
    Player.cpp
    BowlingGame.cpp
)

# Enable Testing and add the test subdirectory
enable_testing()
add_subdirectory(test)
