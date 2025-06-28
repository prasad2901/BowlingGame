#ifndef FRAME_HPP
#define FRAME_HPP

#include <iostream>

class Frame {
public:
    Frame(int r1 = 0, int r2 = 0, int r3 = 0);

    int getFirst() const;
    int getSecond() const;
    int getThird() const;

    bool isStrike() const;
    bool isSpare() const;

    int getTotal() const;

private:
    int roll1, roll2, roll3;
};

#endif
