if(EXISTS "/home/infl72/Downloads/Bowling/build/test/BowlingGameTests[1]_tests.cmake")
  include("/home/infl72/Downloads/Bowling/build/test/BowlingGameTests[1]_tests.cmake")
else()
  add_test(BowlingGameTests_NOT_BUILT BowlingGameTests_NOT_BUILT)
endif()
