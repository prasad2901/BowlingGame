#include "Frame.hpp"

Frame::Frame(int r1, int r2, int r3) : roll1(r1), roll2(r2), roll3(r3) {}

int Frame::getFirst() const {
    return roll1;
}

int Frame::getSecond() const {
    return roll2;
}

int Frame::getThird() const {
    return roll3;
}

bool Frame::isStrike() const {
    return roll1 == 10;
}

bool Frame::isSpare() const {
    return roll1 != 10 && (roll1 + roll2 == 10);
}

int Frame::getTotal() const {
    return roll1 + roll2 + roll3;
}
