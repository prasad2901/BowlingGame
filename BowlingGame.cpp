#include "BowlingGame.hpp"

BowlingGame::BowlingGame(){}

void BowlingGame::addFrame(const Frame &frame)
{
    if (currFrame >= 10) {
        throw std::runtime_error("Cannot add more than 10 frames.");
    }
    frames[currFrame++] = frame;
}

int BowlingGame::calculateScore() const {
    int totalScore = 0;
    for (size_t i = 0; i < 10; i++) {
        const auto& f = frames[i];

        if (i < 9) {
            if (f.isStrike()) {
                totalScore += 10 + getNextTwoRolls(i);
            } else if (f.isSpare()) {
                totalScore += 10 + getNextOneRoll(i);
            } else {
                totalScore += f.getFirst() + f.getSecond();
            }
        } else {
            totalScore += f.getTotal();
        }
    }
    return totalScore;
}

int BowlingGame::getNextTwoRolls(size_t frameIndex) const {
    // Check if there is one more frame left
    if (frameIndex + 1 >= frames.size()) return 0;

    const Frame& nextFrame = frames[frameIndex + 1];

    // If the next frame is a strike, we need to look for next frames
    if (nextFrame.isStrike()) {
        if (frameIndex + 2 < frames.size()) {
            // 10 from next frame + first score of next to next frame
            return 10 + frames[frameIndex + 2].getFirst();
        } else {
            return 10;
        }
    }

    // Use both the scores from the next frame
    return nextFrame.getFirst() + nextFrame.getSecond();
}


int BowlingGame::getNextOneRoll(size_t frameIndex) const {
    // Check if there is one more frame left
    if (frameIndex + 1 >= frames.size()) return 0;

    // Return the first score of the next frame
    return frames[frameIndex + 1].getFirst();
}
