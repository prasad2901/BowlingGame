# BowlingGame
A console application along with the unit test cases and UML diagram.

For Compiling and building the Project

Step1: mkdir build

Step2: cd build

Step3: cmake -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON ..

Step4: make

After this the ./BowlingGame application and the ./test/BowlingGameTests both the binaries are generated

Generating code coverage

Step5: lcov --capture --directory . --output-file coverage.info

Step6: lcov --remove coverage.info '/usr/*' --output-file coverage.info

Step7: genhtml coverage.info --output-directory coverage-report

The code coverage report is generated in the coverage-report which can be seen on web

Step8: xdg-open coverage-report/index.html
