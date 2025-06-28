# GoogleTest-based test binary
add_executable(BowlingGameTests
    test.cpp
    ../Frame.cpp
    ../Player.cpp
    ../BowlingGame.cpp
)

target_include_directories(BowlingGameTests PRIVATE ../)

find_package(GTest REQUIRED)
target_link_libraries(BowlingGameTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(BowlingGameTests)
