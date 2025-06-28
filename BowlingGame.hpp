#ifndef BOWLINGGAME_HPP
#define BOWLINGGAME_HPP

#include <array>
#include <stdexcept>
#include "Frame.hpp"

class BowlingGame {
public:
    BowlingGame();

    void addFrame(const Frame& frame);
    int calculateScore() const;

private:
    // Array to store 10 frames because they are only 10 fixed
    std::array<Frame, 10> frames;
    size_t currFrame = 0;

    int getNextTwoRolls(size_t frameIndex) const;
    int getNextOneRoll(size_t frameIndex) const;
};

#endif
